#include "MyString.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

CMyString::CMyString(void)
	: m_pszData(nullptr), m_nLength(0)
{
	//	cout << "CMyString()" << endl;
}

CMyString::CMyString(const char* pszParam)
	: m_pszData(nullptr), m_nLength(0)
{
	//	cout << "CMyString(const char*)" << endl;
	setString(pszParam);
}

CMyString::CMyString(const CMyString & rhs)
	: m_pszData(nullptr), m_nLength(0)
{
	//	cout << "CMyString(const CMyString &)" << endl;
	this->setString(rhs.m_pszData);
}

CMyString::~CMyString(void)
{
	//	cout << "~CMyString()" << endl;
	release();
}

int CMyString::setString(const char * pszParam)
{
	release();
	if (pszParam == nullptr)	return 0;

	// 1. �Ű������� ���޵� ���ڿ��� ���� ����
	m_nLength = (int)strlen(pszParam);
	if (m_nLength == 0)		return 0;

	// 2. �Ű������� ���޵� ���ڿ��� ����� �� �ִ�
	//	  �޸� ���� �Ҵ�
	//	m_pszData = (char*)calloc( m_nLength + 1, sizeof(char) );
	m_pszData = new char[m_nLength + 1];
	// 3. ���� �Ҵ��� �޸𸮿� ���ڿ� ����
	strcpy_s(m_pszData, sizeof(char) * (m_nLength + 1), pszParam);

	// �̷��� �ڵ带 ����
	onSetString(m_pszData);

	// ���1. ���� �Ű������� NULL�̰ų� ���ڿ��� ���̰�
	//		  0�̶��, � ó���� �����Ѱ�?
	// ���2. ���� �Ҵ�� �޸𸮴� ���� ��� �����ϴ°�.
	// ���3. ���� ����ڿ� ���� �� �Լ��� 2ȸ ȣ��ȴٸ�
	//		  ���� �ۼ��� �ڵ忡 ������ ���°�?
	return m_nLength;
}

void CMyString::release(void)
{
	// 1. m_pszData����� ����Ű�� �޸𸮸� ����.
	delete[] m_pszData;
	// 2. �޼����� �������� ȣ�� ������ ����ڰ�
	//	  �����Ѵ�. �׷��Ƿ� �޸𸮸� ������
	//	  ���ķ� � �ڵ尡 �߰��Ǿ�� �̾�����
	//	  ����� �ڵ��� ������ �帧�� ������
	//	  ���� ���� �� �ִ°�?
	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator =(const CMyString &strParam)
{
	if (this != &strParam)
		setString(strParam.m_pszData);

	return *this;
}

CMyString& CMyString::operator =(const char * pszParam)
{
	if (this->m_pszData != pszParam)
		setString(pszParam);

	return *this;
}

CMyString CMyString::operator +(const CMyString & rhs)
{
	CMyString strResult(*this);
	strResult.append(rhs.m_pszData);
	return strResult;
}

int CMyString::append(const char* pszParam)
{
	if (pszParam == NULL)	return 0;

	int nLenParam = (int)strlen(pszParam);
	if (nLenParam == 0)		return 0;

	if (m_pszData != NULL)
	{
		int nLenResult = m_nLength + nLenParam;
		char *pszResult = new char[nLenResult + 1];
		strcpy_s(pszResult, m_nLength + 1, m_pszData);
		strcpy_s(pszResult + m_nLength, nLenParam + 1, pszParam);

		release();
		m_pszData = pszResult;
		m_nLength = nLenResult;
	}
	else
	{
		this->operator = (pszParam);
	}
	return 0;
}

CMyString CMyString::operator +(const char* pszParam)
{
	CMyString strResult(*this);
	strResult.append(pszParam);
	return strResult;
}

// ���� �Լ�
CMyString operator + (const char *pszLeft, const CMyString & strRight)
{
	CMyString strResult(pszLeft);
	strResult.append(strRight.m_pszData);
	return strResult;
}

int CMyString::testFunc(const char* pszParam)
{
	return setString(pszParam);
}

int CMyString::onSetString(const char *pszParam)
{
	return 1;
}
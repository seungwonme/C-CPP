#include <iostream>

using namespace std;

void testFunc()
{
	cout << "::testFunc()" << endl;
}

namespace Test
{
	void testFunc()
	{
		cout << "Test::testFunc()" << endl;
	}
}

namespace MyData
{
	void testFunc()
	{
		cout << "MyData::testFunc()" << endl;
	}
}

int main()
{
	testFunc();
	::testFunc();
	Test::testFunc();
	MyData::testFunc();

	return 0;
}

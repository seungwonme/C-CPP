#include <iostream>
using namespace std; // std:: 생략 가능

int data = 100;

namespace Test
{
	// int data = 100;
	void print()
	{
		// cout << data << endl;
		cout << ::data << endl;
	}
}

namespace A
{
	void print()
	{
		cout << "A" << endl;
	}
	namespace sub
	{
		void print()
		{
			cout << "A::sub" << endl;
		}
	}
	
}

namespace B
{
	void print()
	{
		cout << "B" << endl;
	}
}

// C++ 17 이상부터는 아래와 같이 namespace를 중첩해서 사용할 수 있음
namespace C::sub
{
	void print()
	{
		cout << "C::sub" << endl;
	}
}

void print()
{
	cout << "Global" << endl;
}

int	main(void)
{
	A::print();
	A::sub::print();
	B::print();
	C::sub::print();
	::print(); // :: 생략 가능
	return 0;
}

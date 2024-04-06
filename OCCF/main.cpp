#include <iostream>

class Foo
{
private:
    int mDataMember;
public:
    Foo(int dataMember) : mDataMember(dataMember) {}
    ~Foo() {}
    Foo(const Foo &rhs) : mDataMember(rhs.mDataMember) {}
    const Foo& operator=(const Foo &rhs)
    {
        if (this != &rhs)
        {
            mDataMember = rhs.mDataMember;
        }
        return *this;
    }
    void PrintDataMember() const
    {
        std::cout << mDataMember << std::endl;
    }
};

int main(void)
{
    Foo foo(1);
    Foo poo(2);

    (foo = poo).PrintDataMember();
    // (foo = poo)가 복사 대입 연산자를 호출하고 그 결과는 *this이므로, PrintDataMember()를 호출할 수 있다.
    // 복사 대입 연산자가 *this를 반환하는 이유

    int i = 1;
    int& j = i;

    if ((i = j) == i)
    {
        std::cout << "True" << std::endl;
    }
    return 0;
}

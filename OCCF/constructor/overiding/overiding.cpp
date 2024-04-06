#include <iostream>

class Foo
{
private:
    int nData;
public:
    // explicit Foo(int data) : nData(data) 암시적 변환을 막기 위해 explicit 키워드를 사용한다.
    Foo(int data) : nData(data) 
    {
        std::cout << "Constructor" << std::endl;
    };
    ~Foo() {};
    void    PrintData(void) { std::cout << nData << std::endl; };
};

int	main(void)
{
    Foo foo(42);

    foo = 22; // 암시적 변환 발생
    foo.PrintData();
    return 0;
}

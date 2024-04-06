#include <iostream>

class Foo
{
public:
    Foo() {};
    ~Foo() {};
    Foo(const Foo &rhs) 
    {
        *this = rhs;
    };
    const Foo& operator=(const Foo& rhs) 
    {
        if (this == &rhs) 
        {
            std::cout << "Here" << std::endl;
            return *this;
        }
        *this = rhs;
        return *this;
    }
};

int	main(void)
{
    Foo foo;
    foo = foo;
    return 0;
}

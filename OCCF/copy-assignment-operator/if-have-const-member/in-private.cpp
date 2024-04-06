#include <iostream>

class Human
{
private:
    const std::string name;
    // const Human &operator=(const Human &rhs);
public:
    Human(const std::string &name) : name(name) {};
    ~Human() {};
    Human(const Human &rhs) : name(rhs.name) {}
    // const Human &operator=(const Human &rhs) {
    //     if (this != &rhs) {
    //         name = rhs.name;
    //     }
    //     return *this;
    // }
};

int main()
{
    Human h1("John");
    Human h2("Doe");
    h1 = h2;
    return 0;
}

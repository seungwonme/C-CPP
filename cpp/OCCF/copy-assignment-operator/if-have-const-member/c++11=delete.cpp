#include <iostream>

class Human
{
private:
    const std::string name;
    const Human &operator=(const Human &rhs) = delete;
    // c++11에서 추가된 문법으로, 클래스 설계자가 특정 함수를 삭제할 수 있게 해준다.
public:
    Human(const std::string &name) : name(name) {};
    ~Human() {};
    Human(const Human &rhs) : name(rhs.name) {}
};


int	main(void)
{
    Human h1("John");
    Human h2("Doe");

    h1 = h2; // error: use of deleted function 'Human& Human::operator=(const Human&)'
    return 0;
}

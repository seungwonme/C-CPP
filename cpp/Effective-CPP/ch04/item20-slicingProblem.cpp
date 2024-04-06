#include <iostream>

class Window
{
private:
public:
	std::string name() const { return "Window"; };
	virtual void display() const { std::cout << "Window::display()" << std::endl; };
};

class WindowWithScrollBars : public Window
{
private:
public:
	virtual void display() const { std::cout << "WindowWithScrollBars::display()" << std::endl; };
};

// void printNameAndDisplay(Window w)
// Window w는 복사 생성자를 호출하므로 Window 객체에 대한 정보만을 가지고 있음

// const Window& w로 하면 WindowWithScrollBars 객체 그대로를 전달할 수 있음
void printNameAndDisplay(const Window& w)
{
	std::cout << w.name() << std::endl;
	w.display();
}

int	main(void)
{
	WindowWithScrollBars wwsb;
	printNameAndDisplay(wwsb);
	return 0;
}

#include <iostream>

// export MallocStackLogging=1 find leaks after unset MallocStackLogging
// if you want more info about leaks use gcc -g option
// while true; do leaks minishell; sleep 1; done;
void	leak(void)
{
	system("leaks --list a.out");
}

class SpecialString: public std::string
{
private:
	char* mData;
public:
	SpecialString() {};
	SpecialString(const char* str)
	{
		size_t len = strlen(str);
		mData = new char[len + 1];
		strcpy(mData, str);
	};
	~SpecialString() {};
};

int	main(void)
{
	atexit(leak);
	SpecialString* pss = new SpecialString("Impending Doom");

	std::string* ps;

	ps = pss; // SpecialString* => std::string*

	delete ps;
	return 0;
}

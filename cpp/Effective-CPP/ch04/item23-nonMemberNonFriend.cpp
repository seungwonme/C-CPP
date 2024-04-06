#include <iostream>

class WebBrowser
{
private:
	
public:
	void ClearCache()
	{
		std::cout << "ClearCache" << std::endl;
	};
	void ClearHistory()
	{
		std::cout << "ClearHistory" << std::endl;
	};
	void RemoveCookies()
	{
		std::cout << "RemoveCookies" << std::endl;
	};

	// 멤버 함수
	void ClearEverything(WebBrowser& wb)
	{
		wb.ClearCache();
		wb.ClearHistory();
		wb.RemoveCookies();
	};
};

// 비멤버 비프렌드 함수
void ClearBrowser(WebBrowser& wb)
{
	wb.ClearCache();
	wb.ClearHistory();
	wb.RemoveCookies();
};


int	main(void)
{
	
	return 0;
}

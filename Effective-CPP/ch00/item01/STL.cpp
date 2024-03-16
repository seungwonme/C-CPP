// 4. STL

/* 
STL은 C++ 표준 라이브러리로, 여러 템플릿 클래스와 함수를 제공하여 자주 사용되는 자료 구조와 알고리즘을 효율적으로 구현할 수 있게 도와준다.
벡터, 리스트, 큐, 스택 등의 자료 구조와 정렬, 검색, 반복자 등의 알고리즘을 제공한다.
STL을 사용하면 개발자가 직접 자료 구조나 알고리즘을 구현하지 않고도 효율적인 코드를 작성할 수 있다.
*/

#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << std::endl;
	return 0;
}


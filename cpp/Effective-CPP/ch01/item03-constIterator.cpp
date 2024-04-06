#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> vec;

	vec.push_back(10);

	const std::vector<int>::iterator iter = vec.begin();
	// iter은 T* const처럼 동작한다.

	*iter = 10; // ok
	// ++iter; // error

	std::vector<int>::const_iterator cIter = vec.begin();
	// cIter은 const T*처럼 동작한다.

	// *cIter = 10; // error
	++cIter; // ok
	return 0;
}

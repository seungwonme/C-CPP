#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void	print(int a) {cout << a << '\n';};
void	print(char b) {cout << b << '\n';};
void	print(double c) {cout << c << '\n';};

int	main() {
	print((int)1);
	print((char)'a');
	print((double)1.1);
	return 0;
}

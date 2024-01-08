void	swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int	main(void)
{
	int a = 5, b = 10;
	::swap(a, b);
	return 0;
}

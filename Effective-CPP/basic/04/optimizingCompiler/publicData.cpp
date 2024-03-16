class Test
{
public:
	int mData;
	Test() 
	: mData(0) {};
	const int	GetData(void)
	{
		return mData;
	}
};

int	main(void)
{
	Test a;
	a.mData;
	return 0;
}

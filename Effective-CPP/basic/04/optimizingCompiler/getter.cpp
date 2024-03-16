class Test
{
private:
	int mData;
public:
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
	a.GetData();
	return 0;
}

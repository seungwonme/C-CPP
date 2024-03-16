#include <stdio.h>

class USERDATA
{
public:
	int mAge;
	char mName[32];
	void PrintUser() const
	{
		printf("%d, %s\n", mAge, mName);
	};
};

int	main(void)
{
	USERDATA user = { 24, "seunan" };
	user.PrintUser();
	return (0);
}

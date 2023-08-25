// https://reakwon.tistory.com/14

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	arr[10] = "world";
// 	char	*ptr = "hello";

// 	// ptr = arr; // ok
// 	// printf("%s\n", ptr);
// 	// arr = ptr; // error
// 	strcpy(arr, ptr); // ok
// 	printf("%s\n", arr);
// 	return (0);
// }

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	arr[4];
	char	*ptr = "hello";

	strcpy(arr, ptr); // buffer overflow
	printf("%s\n", arr);
	return (0);
}

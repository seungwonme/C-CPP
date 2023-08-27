#include <stdio.h>

int main(void)
{
  char str[] = {'h','i','!','\0'};
  printf("%s\n",str);
  printf("%lu\n",sizeof(str));

  char str1[] = "hi!"; // [h][i][!][\0]
  // 문자열 변수의 이름은 시작점의 정보를 알려준다.
  // NULL(\0)은 문자열이 마지막의 정보를 알려준다.
  printf("%s\n",str1);
  printf("%lu\n",sizeof(str1)); // 4

  return 0;
}
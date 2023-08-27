#include <stdio.h>

int main(int argc, char const *argv[])
{
  if(argc != 2)
  {
    printf("missing command-line argument\n");
    return 1; // 문제가 없으면 0 반환, 나머지는 문제가 있다는 뜻
  }
  else
  {
    // printf("hello, %s\n",argv[0]); hello, ./exit
    printf("hello, %s\n",argv[1]); 
  }
  return 0;
}
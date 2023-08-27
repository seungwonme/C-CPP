#include <stdio.h>

int main(void)
{
  char* names[4] = {"sandy","seungwon","dean"}; // char* 포인터 변수를 선언 후 문자열 넣으면 문자열이 담긴 배열 생성 가능

  printf("%lu\n",sizeof(names)); // 32
  printf("%lu\n",sizeof(names[2])); // 8 이런 식으로 배열을 만들면 최대로 설정하나봄

  printf("%s\n",names[2]); // dean
  printf("%c%c%c%c%i\n",names[2][0],names[2][1],names[2][2],names[2][3],names[2][4]); // dean0 (\0의 아스키번호)
  return 0;
}
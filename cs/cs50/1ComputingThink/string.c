#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[32];
  printf("Input : ");
  scanf("%s",str); // &을 안쓰는 이유는 str이 시작점의 주솟값을 가지고 있기 때문이다.
  printf("Output : ");
  /* // 방법 1 NULL 문자와 비교
  int i = 0;
  while (str[i] != '\0') // /n, /0 한 글자 취급
  {
    printf("%c",str[i]);
    i++;
  }
  printf("\n"); */

  // 방법 2 문자열의 길이 만큼 반복 (일일이 NULL과 비교하는 것보다 효율적이다.)
  for (int i = 0, n = strlen(str); i < n; i++) // 함수를 반복실행하지 않기 위해 변수 n에 값 저장
  // string.h 내장 함수 
  {
    printf("%c",str[i]);
  }
  printf("\n");
  return 0;
}
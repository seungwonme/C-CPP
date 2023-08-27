#include <stdio.h>
#include <string.h> // strcmp

int main(void)
{
  char *names[4] = {"EMMA","RODRIGO","BRIAN","DAVID"};
  for (int i = 0; i < 4; i++)
  {
    /* if (names[i] == "EMMA") // 문자열은 ==으로 비교가 불가능 숫자,문자가 아니고 문자로 된 배열이기 때문
    {
      printf("Found\n");
      return 0;
    } */
    if (strcmp(names[i], "EMMA") == 0) // 같다면 0 반환 양수 반환 시 첫 문자열이 알파벳 기준으로 큰 경우 음수면 반대의 경우
    {
      printf("Found\n");
      return 0; // success
    }
  }
  printf("Not found\n");
  return 1; // fail
}
#include <stdio.h>
#include <unistd.h> // sleep 사용하기 위해

int main(void)
{
  for (int i = 1; ; i *= 2)
  {
    printf("%i\n", i);
    sleep(1); // 1초를 쉰다.
    // 1073741824 -> -2147483648 -> 0 -> 0 ...
    // 3칸밖에 사용하지 못할 때 999에 1을 더하면 1이 생략되어 000 즉, 0으로 표현된다. 이런 경우를 overflow라 한다.
  }
}
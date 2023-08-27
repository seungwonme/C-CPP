// O(n^2) Ω(n)

#include <stdio.h>

int main(void)
{
  int n, swap; // 몇개의 숫자 입력받을 것인지, swap 변수
  scanf("%d", &n);
  int arr[n]; // arr: 사용자 입력값 받을 배열
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]); // 사용자 입력값 받기
  }

  int times = 0; // 정렬되기까지의 연산 횟수

  // 배열 정렬하기
  for (int i = 0; i < n - 1; i++)
  {
    int cnt = 0; // 만약 if문에 걸리지 않으면 이미 정렬된 배열이기 때문에 낭비를 막기 위해 if문에 걸린 횟수를 카운트해서 걸리지 않았다면 break
    for (int j = 0; j < n - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
        cnt++;
      }
      times++;
    }
    if (cnt == 0) // 이 if문으로 최소 실행시간을 단축할 수 있다.
      break;
  }

  // 정렬된 배열 출력
  for (int i = 0; i < n; i++)
  {
    printf("%d", arr[i]);
    if (i == n - 1)
    {
      printf("\ntimes : %d\n", times);
      break;
    }
    printf(" ");
  }
  if (-1 == remove("bubbleSort"))
    return 0;
}
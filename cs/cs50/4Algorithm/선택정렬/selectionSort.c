// O(n^2) Ω(n^2)

#include <stdio.h>

const int MAX = 10000; // 나올 수 있는 가장 큰 수

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
  for (int j = 0; j < n; j++)
  {
    int min = MAX; // 사용자 입력값 중 최솟값 찾기
    int idx = 0;   // 최솟값의 인덱스
    for (int k = j; k < n; k++)
    {
      if (arr[k] < min)
      {
        min = arr[k];
        idx = k;
      }
      times++;
    }
    swap = arr[j];
    arr[j] = arr[idx];
    arr[idx] = swap;
  }

  // 정렬된 배열 출력
  for (int l = 0; l < n; l++)
  {
    printf("%d", arr[l]);
    if (l == n - 1)
    {
      printf("\ntimes : %d\n",times);
      break;
    }
    printf(" ");
  }
  if (-1 == remove("selectionSort"))
    return 0;
}
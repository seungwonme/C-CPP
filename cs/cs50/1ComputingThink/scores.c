#include <stdio.h>

// const int N = 3;

int get_int(char greet[50]);
float average(int arr[], int length);

int main()
{
  // lv 1
  float score1 = 72;
  float score2 = 73;
  float score3 = 33;
  printf("Average : %.2f\n",(score1+score2+score3)/3);

  /* // lv 2
  float scores[N] = {72,73,33};
  float total = 0;
  for (int i = 0; i < N; i++)
  {
    total += scores[i];
  }
  printf("Average : %.2f\n",total/N); */

  // lv 3
  int m = get_int("Number of scores : ");
  int scores[m];
  for (int i = 0; i < m; i++)
  {
    printf("score %i: ",i + 1);
    scanf("%i",&scores[i]);
  }
  printf("Average : %.1f",average(scores,m));
  return 0;
}

int get_int(char greet[50])
{
  int integer;
  printf("%s",greet);
  scanf("%d",&integer);
  return integer;
}

float average(int arr[], int length)
{
  int total = 0;
  for (int i = 0; i < length; i++)
  {
    total += arr[i];
  }
  return (float) total/ (float) length;
}
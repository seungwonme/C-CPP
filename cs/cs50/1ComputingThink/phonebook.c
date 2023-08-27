#include <stdio.h>
#include <string.h>

typedef struct
{
  char *name;
  char *number;
}
person;

int main(void)
{
  /* // 구조체를 사용하지 않았을 때
  char *names[4] = {"EMMA","RODRIGO","BRIAN","DAVID"};
  char *numbers[4] = {"010-1234-5678","011-1234-5678","012-1234-5678","013-1234-5678"};
  for (int i = 0; i < 4; i++)
  {
    if(strcmp(names[i],"BRIAN")==0)
    {
      printf("%s\n",numbers[i]);
      return 0;
    }
  }
  printf("Not found\n"); */
  // 구조체를 사용할 때
  person people[4];

  people[0].name = "EMMA";
  people[0].number = "010-1234-5678";

  people[1].name = "RODRIGO";
  people[1].number = "011-1234-5678";

  people[2].name = "BRIAN";
  people[2].number = "012-1234-5678";

  people[3].name = "DAVID";
  people[3].number = "013-1234-5678";

  for (int i = 0; i < 4; i++)
  {
    if(strcmp(people[i].name,"BRIAN")==0)
    {
      printf("%s\n",people[i].number);
      return 0;
    }
  }
  printf("Not found\n");

  return 1;
}
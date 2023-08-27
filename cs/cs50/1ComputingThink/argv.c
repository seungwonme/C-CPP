#include <stdio.h>

// ARGument Count, ARGument Vector
int main(int argc, char const *argv[])
{
  if(argc == 2)
  {
    printf("hello, %s\n",argv[1]);
  }
  else
  {
    printf("hello, world\n");
  }
  
  return 0;
}

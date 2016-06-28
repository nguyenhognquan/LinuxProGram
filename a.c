#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void display(int a)
{
  printf("pid : %d\n", getpid());
  printf("value of b: %d\n", a);
}

int main()
{
  int *pa = (int*)malloc(10*sizeof(int));
  int i  = 0;
  pid_t pid;
  switch(pid = fork())
    {
    case -1:
      return -1;
    case 0:
      {
	int b = 20;
	printf("value b: %d\n", b++);
        display(b);
      }
      break;
    default:
      {
	int b = 30;
	printf("value of b : %d\n", b++);
        display(b);
      }
    }
  for(i = 0; i< 10; i++)
    {
      printf("get pid : %d\n", getpid());
      *(pa + i) = i;
    }
  sleep(10);
  return 0;
}

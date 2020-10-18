#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
  clock_t start;
  int n;
  int sec;
  printf("enter the number");
  start= clock();
  scanf("%d",&n);
  start=clock()-start;
  sec=((int)start)/CLOCKS_PER_SEC;
  printf("time taken is %d",sec);
  return 0;
}

#include "syscall.h"
#include "stdio.h"
#include "stdlib.h"

#define BUFSIZE 1024

char buf[BUFSIZE];

int main(int argc, char** argv)
{
  int src, dst, amount;

  if (argc!=3) {
    printf("Usage: cp <src> <dst>\n");
    return 1;
  }

  printf("++cp: I'm OK now\n");
  printf("++cp: arg0 %s\n", argv[0]);
  printf("++cp: arg1 %s\n", argv[1]);
  printf("++cp: arg2 %s\n", argv[2]);

  src = open(argv[1]);
  if (src==-1) {
    printf("++cp: Unable to open %s\n", argv[1]);
    return 1;
  }

  printf("++cp: create %s\n", argv[2]);
  creat(argv[2]);
  dst = open(argv[2]);
  if (dst==-1) {
    printf("++cp: Unable to create %s\n", argv[2]);
    return 1;
  }

  while ((amount = read(src, buf, BUFSIZE))>0) {
    write(dst, buf, amount);
  }

  close(src);
  close(dst);

  return 0;
}



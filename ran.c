#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int ran(){
  int num;
  int x = open("/dev/random", O_RDONLY);
  read(x,&num,sizeof(num));
  return num;
}

int main(){
  int aran[10];
  int sran[10];

  printf("generating random numbers: \n");
  int i = 0;
  while(i < 10){
    aran[i] = ran();
    printf("  random %d: %d \n", i, aran[i]);
    i++;
  }
  printf("\n");

  printf("writing numbers to file... \n");
  int x = open("text.txt", O_WRONLY);
  if(x < 0)
    printf("open error: %s \n", strerror(errno));

  int w = write(x,aran,10 * sizeof(int));
  if(w < 0)
    printf("write error: %s \n", strerror(errno));
  close(x);
  printf("\n");


  printf("reading numbers from file... \n");
  x = open("text.txt", O_RDONLY);
  if(x < 0)
    printf("open error: %s \n", strerror(errno));

  int r = read(x,sran,10 * sizeof(int));
  if(r < 0)
    printf("read error: %s \n", strerror(errno));
  close(x);
  printf("\n");


  printf("verification that written values were the same: \n");
  int j = 0;
  while(j < 10){
    printf("  random %d: %d \n", j, sran[j]);
    j++;
  }
  return 0;
}

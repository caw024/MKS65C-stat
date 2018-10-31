#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

//Help received from stack overflow
int stats(char* filename){

  int fd = open(filename, O_RDWR | O_CREAT, 00744);
  printf("File Descriptor: %d\n",fd);


  //populate array with random values
  int randfd = open("/dev/random", O_RDONLY);
  int arr[10];
  int l = read(randfd, arr, 10*sizeof(int));
  int m = close(randfd);


  //write to array
  int writ = write(fd,arr,10*sizeof(int));

  //lseek(writ, 0, SEEK_SET);

  struct stat * info = malloc(sizeof(struct stat));

  stat(filename,info);

  int size = info->st_size;
  int mode = info->st_mode;
  char * recent = ctime(&(info->st_atime));

  printf("This is the file size: %d\n", size);
  printf("This is the mode: %o\n", mode);
  printf("This is when the file was last accessed: %s\n", recent );

  int closed = close(fd);

  return 0;
}

int main(){


  stats("file.txt");

  return 0;
}

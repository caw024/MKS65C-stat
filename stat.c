#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

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

  struct stat info;
  
  lseek(writ, 0, SEEK_SET);

  stat(filename,&info);
  int success = info.st_size;
  
  printf("This is the file size: %d\n", success);

  
  int closed = close(fd);

  return 0; 
}

int main(){
 
  
  stats("file.txt");
  
  return 0;
}

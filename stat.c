#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int stats(char* filename){
  
  int fd = open(filename,O_RDWR | O_CREAT, 00744);
  printf("File Descriptor: %d\n",fd);

  int closed = close(fd);
  //int size = lseek(fd,4, SEEK_SET); 
   

  struct stat info;

  int success = stat("./file.txt",info);
  
  printf("This is the file size: %d/n", info.st_size);
  return 0; 
}

int main(){
  stats("file.txt");
  return 0;
}

#include <stdio.h>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>
#include "JsonDriver.h"

using namespace std;

int main(int argc, char **argv){
  const char *buf = "[ \"a1\", \"a2\", [\"b1\", \"b2\", \"b3\"], \"a3\"]";
  char *other;
  int fd;
  string inp;
  JSON::JsonDriver *jd;
  JsonRoot *jr;
  struct stat bfs;
  if(argc == 1){
    inp = string(buf);
    jd = new JSON::JsonDriver();
    jr = jd->parse(inp);
    inp = jr->serialize();
    printf("Result: %s\n", inp.c_str());
  }else{
    fd = open(argv[1], O_RDONLY);
    if(fd < 0 ){
      printf("failed to open file\n");
      return -1;
    }
    if(fstat(fd, &bfs) != 0){
      printf("stat failed\n");
      return -1;
    }
    other = (char*)malloc(bfs.st_size);
    if(read(fd, other, bfs.st_size) != bfs.st_size){
      close(fd);
      printf("read failed\n");
      return -1;
    }
    close(fd);
    inp = string(other);
    jd = new JSON::JsonDriver();
    jd->parse(inp);    
  }
}

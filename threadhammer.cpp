#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
  if(argc != 2){
    printf("Usage threadhammer <filename>\n");
    return -1;
  }
  std::ifstream file(argv[1]);
  std::string line;
  while(std::getline(file,line)){
    printf("%s\n", line.c_str());
  }
  
}

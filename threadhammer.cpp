#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ThreadParseTest.h"

void singleTest(){
  const char *buf = "[ \"a1\", \"a2\", [\"b1\", \"b2\", \"b3\"], \"a3\"]";
  JSON::JsonDriver *jd;
  std::string inp;
  JsonRoot *jr;
  inp = std::string(buf);
  jd = new JSON::JsonDriver();
  jr = jd->parse(inp);
  inp = jr->serialize();
  printf("Result: %s\n", inp.c_str());  
}

void fileTest(const char *pFilename){
  std::ifstream file(pFilename);
  std::string line;
  std::vector<std::string> inplist;
  std::vector<ThreadParseTest*> tptlist;
  ThreadParseTest *tmp;
  int ipt;
  unsigned int c;
  int j;
  bool testdone;
  ipt = 25;
  inplist.clear();
  tptlist.clear();
  while(std::getline(file,line)){
    inplist.push_back(line);
  }
  if(inplist.size() == 0){
    printf("Input file empty\n");
    return;
  }
  j = 0;
  tmp = new ThreadParseTest();
  for(c = 0; c < inplist.size(); c++){
    if(j > ipt){
      j = 0;
      tptlist.push_back(tmp);
      tmp = new ThreadParseTest();      
    }
    j++;
    tmp->addString(inplist[c]);
  }
  tptlist.push_back(tmp);
  for(c = 0; c < tptlist.size(); c++){
    tptlist[c]->build();    
  }
  testdone = false;
  while(testdone == false){
    testdone = true;
    for(c = 0; c < tptlist.size(); c++){
      if(tptlist[c]->done() == false){
	testdone = false;
      }
    }
  }
  for(c = 0; c < tptlist.size(); c++){
    if(tptlist[c]->check() == false){
      printf("Test failed thread %d\n",c);
      return;
    }    
  }
  printf("Test passed\n");
}

int main(int argc, char **argv){
  if(argc == 1){
    singleTest();
  }else if(argc == 2){
    fileTest(argv[1]);
  }
}

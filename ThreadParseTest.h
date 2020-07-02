#ifndef THREAD_PARSE_TEST_H
#define THREAD_PARSE_TEST_H

#include <pthread.h>
#include <vector>
#include <string>
#include "JsonDriver.h"
#include "JsonRoot.h"
class ThreadParseTest{
 public:
  ThreadParseTest();
  void addString(std::string &pInput);
  void __run();
  void build();
  bool done();
  bool check();  
 private:
  bool mValid;
  bool mDone;
  std::vector<std::string> mInputList;
  std::vector<JsonRoot *> mParsed;
  pthread_t mThread;
};

#endif


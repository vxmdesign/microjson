#include "ThreadParseTest.h"

void * __private_thread_run(void *arg){
  ThreadParseTest *tpt;
  tpt = (ThreadParseTest*)arg;
  tpt->__run();
  return NULL;
}

ThreadParseTest::ThreadParseTest(){
  mInputList.clear();
  mParsed.clear();
  mDone = false;
}

void ThreadParseTest::addString(std::string &pInput){
  mInputList.push_back(pInput);
}

void ThreadParseTest::__run(){
  unsigned int c;
  JSON::JsonDriver jd;
  JsonRoot *jr;
  for(c = 0; c < mParsed.size(); c++){
    delete mParsed[c];
  }
  mParsed.clear();
  mValid = true;
  for(c = 0; c < mInputList.size(); c++){
    jr = jd.parse(mInputList[c]);
    if(jr == NULL){     
      mValid = false;
    }else{
      mParsed.push_back(jr);
    }
  }
  mDone = true;  
}

bool ThreadParseTest::done(){
  return mDone;
}

bool ThreadParseTest::check(){
  unsigned int c;
  JsonRoot *jr;
  JSON::JsonDriver jd;
  if(mValid == false){
    printf("Test not valid\n");
    return false;
  }
  if(mInputList.size() != mParsed.size()){
    //this shouldn't ever happen
    printf("This is an invalid condition\n");
    return false;
  }
  if(mParsed.size() == 0){
    printf("No parsed items. Should be %d\n", (int)mInputList.size());
    return false;
  }
  for(c = 0; c < mInputList.size(); c++){
    jr = jd.parse(mInputList[c]);
    if(jr == NULL){
      printf("Parse error\n");
      return false;
    }
    if(jr->equals(mParsed[c]) == false){
      printf("Mismatch item %d of %d\n", c, (int)mInputList.size());
      printf("Threaded: %s\n", mParsed[c]->serialize().c_str());
      printf("Testcase: %s\n", jr->serialize().c_str());
      delete jr;
      return false;
    }
    delete jr;    
  }
  return true;
}

void ThreadParseTest::build(){
  mDone = false;
  pthread_create(&mThread, NULL, __private_thread_run, this);
}


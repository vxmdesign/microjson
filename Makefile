SRCS= JsonDriver.cpp JsonString.cpp JsonNumber.cpp JsonBool.cpp JsonNull.cpp JsonArray.cpp JsonObject.cpp BaseJsonList.cpp JsonObjEntry.cpp JsonRoot.cpp BaseJsonNode.cpp
INSTALL_HEADERS= BaseJsonList.h BaseJsonNode.h JsonArray.h JsonBool.h JsonDriver.h uJson.h JsonNull.h JsonNumber.h JsonObject.h JsonObjEntry.h JsonRoot.h JsonScanner.h JsonString.h JsonParser.hpp location.hh stack.hh position.hh

TEST_SRCS= ThreadParseTest.cpp threadhammer.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
TEST_OBJS=$(patsubst %.cpp,%.o,$(TEST_SRCS))
LYOBJS=JsonParser.o JsonScanner.o

CFLAGS= -g -O3 -Wall -fPIC
PREFIX ?= .

all: threadhammer libmicrojson.so

install: libmicrojson.so
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install -m 644 $(INSTALL_HEADERS) $(PREFIX)/include
	install -m 755 libmicrojson.so $(PREFIX)/lib


threadhammer: $(LYOBJS) $(OBJS) $(TEST_OBJS)
	g++ $(CFLAGS) -o $@ $^ -lpthread

libmicrojson.so: $(LYOBJS) $(OBJS)
	g++ $(CFLAGS) -shared -o $@ $^

JsonParser.cpp: json.yy
	bison  -o$@ $^

JsonScanner.cpp: json.l
	flex --outfile=$@ $^

JsonScanner.o: JsonScanner.cpp
	g++ $(CFLAGS)  -c $^

JsonParser.o: JsonParser.cpp
	g++ $(CFLAGS)  -c $^

%.o: %.cpp
	g++ $(CFLAGS) -Werror -c $^


clean:
	rm -f *.o
	rm -f JsonParser.cpp
	rm -f JsonScanner.cpp
	rm -f *.hh
	rm -f *.hpp
	rm -f *.output
	rm -f threadhammer



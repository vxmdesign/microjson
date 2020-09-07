SRCS= JsonDriver.cpp JsonString.cpp JsonNumber.cpp JsonBool.cpp JsonNull.cpp JsonArray.cpp JsonObject.cpp BaseJsonList.cpp JsonObjEntry.cpp JsonRoot.cpp BaseJsonNode.cpp ThreadParseTest.cpp threadhammer.cpp 
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
LYOBJS=JsonParser.o JsonScanner.o



all: threadhammer

threadhammer: $(LYOBJS) $(OBJS)
	g++ -g -O3 -Wall -o $@ $^ -lpthread

JsonParser.cpp: json.yy
	bison  -o$@ $^

JsonScanner.cpp: json.l
	flex --outfile=$@ $^

JsonScanner.o: JsonScanner.cpp
	g++ -g -O3 -Wall  -c $^

JsonParser.o: JsonParser.cpp
	g++ -g -O3 -Wall  -c $^

%.o: %.cpp
	g++ -g -O3 -Wall -Werror -c $^


clean:
	rm -f *.o
	rm -f JsonParser.cpp
	rm -f JsonScanner.cpp
	rm -f *.hh
	rm -f *.hpp
	rm -f *.output
	rm -f threadhammer

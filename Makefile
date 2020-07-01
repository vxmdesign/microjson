SRCS= JsonDriver.cpp main.cpp JsonString.cpp JsonNumber.cpp JsonBool.cpp JsonNull.cpp JsonArray.cpp JsonObject.cpp BaseJsonList.cpp JsonObjEntry.cpp JsonRoot.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
LYOBJS=JsonParser.o JsonScanner.o



all: jsontest

jsontest: $(LYOBJS) $(OBJS)
	g++ -g -Wall -o $@ $^

JsonParser.cpp: json.yy
	bison  -o$@ $^

JsonScanner.cpp: json.l
	flex --outfile=$@ $^

JsonScanner.o: JsonScanner.cpp
	g++ -g -Wall  -c $^

JsonParser.o: JsonParser.cpp
	g++ -g -Wall  -c $^

%.o: %.cpp
	g++ -g -Wall -Werror -c $^


clean:
	rm -f *.o
	rm -f JsonParser.cpp
	rm -f JsonScanner.cpp
	rm -f *.hh
	rm -f *.hpp
	rm -f *.output
	rm -f jsontest

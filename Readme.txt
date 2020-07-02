Microjson parser.

C++ threadsafe parser for json. Takes a std::string and returns a JsonRoot object which contains the data. It does not require a file input.
It does not require any particular version of c++. It does not require cmake or boost or any other crap.
It needs make, g++, flex and bison.

I've tested it on flex as early as 2.5.3, and bison 3.0.2

It was designed to be a tiny json parser meant for dealing with json on the backend of web stuff for getting data into c++ libraries. 

This is meant as a reference and I may or may not update it.

This code compiles with two extra pieces of code for testing purposes:
threadhammer.cpp (contains main)
ThreadParseTest.[cpp|h] (contains a pthreads based parser for testing)

pthread is only necessary for these two pieces of code. Not for the parser.
This code also serves as an example of the application of this parser.

To make:
make

It run the test:
./threadhammer
this does a single simple test that it work
./threadhammer <json file>
This will parse a json file and assumes one complete json node per line. students.json was borrowed from another repo and is included here for this test.

The scanner/parser was batched together from other examples around the internet. The rest of the json infrastructure was written by me in a couple of hours.

If you want to use that Json infrastructure go ahead, and if you want to modify it should be pretty straightforward.

One extra note:
Bison has changed the format for defining the class
 %define parser_class_name {JsonParser}
 This has been deprecated, but the new style doesn't work on every one of my test systems, so between not working on all systems or a warning on some, I choose to have all systems work.
 
-cjwfirmware






Microjson parser.

C++ threadsafe parser for json. Takes a std::string and returns a JsonRoot object which contains the data. It does not require a file input.
It does not require any particular version of c++. It does not require cmake or boost or any other crap.
It needs make, g++, flex and bison.

I've tested it on flex as early as 2.5.3, and bison 3.0.2

It was designed to be a tiny json parser meant for dealing with json on the backend of web stuff for getting data into c++ libraries. 

This is meant as a reference and I may or may not update it.







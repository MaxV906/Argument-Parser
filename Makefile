
all: libparser.o libparser.so compile

libparser.o: lib/parser.c
	gcc -c ./lib/parser.c -o ./lib/libparser.o

libparser.so: lib/parser.c
	gcc ./lib/parser.c -shared -fpic -o ./lib/libparser.so

compile: example.c lib/libparser.o
	gcc -c example.c -o parserexample.o
	gcc -o parserexample parserexample.o ./lib/libparser.o

install: lib/libparser.so
	cp lib/parser.h /usr/include/parser.h
	cp lib/libparser.so /usr/lib/libparser.so

uninstall:
	rm /usr/include/parser.h
	rm /usr/lib/libparser.so

clean:
	rm parserexample parserexample.o ./lib/libparser.so ./lib/libparser.o

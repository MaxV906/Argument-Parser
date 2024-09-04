
all: compile

compile: example.c
	gcc -o parser example.c

install:
	cp parser.h /usr/include/parser.h

uninstall:
	rm /usr/include/parser.h

clean:
	rm parser

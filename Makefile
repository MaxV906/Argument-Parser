SOURCE_FILES = $(wildcard *.c)

all: compile

compile: $(SOURCE_FILES)
	gcc -o parser $(SOURCE_FILES)

install:
	cp parser.h /usr/include/parser.h

clean:
	rm parser
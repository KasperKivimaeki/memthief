all: main

main: 
	gcc -std=c11 main.c -o memthief

install: 
	cp memthief /usr/bin/

clean: 
	rm -f memthief

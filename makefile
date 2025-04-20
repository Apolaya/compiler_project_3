all: compile
compile: scanner.o parser.o listing.o values.o
	g++ -o compile scanner.o parser.o listing.o values.o

scanner.o: scanner.c listing.h tokens.h values.h
	g++ -c scanner.c

scanner.c: scanner.l
	flex scanner.l
	mv lex.yy.c scanner.c

parser.o: parser.c listing.h values.h symbols.h
	g++ -c parser.c

parser.c tokens.h: parser.y
	bison -d -v parser.y
	mv parser.tab.c parser.c
	cp parser.tab.h tokens.h

values.o: values.cc values.h listing.h
	g++ -c values.cc

listing.o: listing.cc listing.h
	g++ -c listing.cc

clean:
	rm -f compile *.o scanner.c parser.c tokens.h parser.output lex.yy.c

.PHONY: clean

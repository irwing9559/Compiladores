ANSI.tab.c: ANSI.y
	bison -d ANSI.y
lex.yy.c: ANSI.l ANSI.tab.c
	flex ANSI.l
ANSI.tab.o: ANSI.tab.c
	gcc ANSI.tab.c -c
lex.yy.o: lex.yy.c
	gcc lex.yy.c -c
a.out: ANSI.tab.o lex.yy.o
	gcc ANSI.tab.o lex.yy.o -ll
run: a.out
	./a.out
clear:
	rm -r a.out *.c *.o *.h

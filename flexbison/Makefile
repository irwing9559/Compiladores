practica.tab.c: practicabison.y
	bison -d practicabison.y
lex.yy.c: practicabison.l practicabison.tab.c
	flex practicabison.l
practica.tab.o: practicabison.tab.c
	gcc practicabison.tab.c -c
lex.yy.o: lex.yy.c
	gcc lex.yy.c -c
a.out: practicaboison.tab.o lex.yy.o
	gcc practicabison.tab.o lex.yy.o -ll
run: a.out
	./a.out
clear:
	rm -r a.out *.c *.o *.h

#include <stdio.h>
//#include <conio.h>
#include <string.h>
#define MAXIMO 30

struct LIFO {
	int t;
	char a[MAXIMO];
};

void main ()
{
	char posfijo [100],infijo[100];
	void in_a_pos (char *infijo,char *posfijo);
	int i;

	printf ("*****Infijo a Posfijo.*****\n");
	printf ("Se pueden usar estos operadores: +,*,|,.,-  \n");
	printf ("Ingrese la cadena para convertirla a Posfijo\n");
	//gets (infijo);
        printf ("\n");
        scanf("%*c%[^\n]",infijo);
	i = strlen (infijo);
	infijo [i] = '#';
	infijo [i+1] = '\0';
	in_a_pos (infijo,posfijo);
	printf ("\n\n");
	printf ("Infijo:\n");
	printf ("%s  \n",infijo);
        printf ("\n\n");
        printf ("%s -> %s  \n",infijo,posfijo);
        printf ("\n\n");
	printf ("Posfijo:\n");
	printf ("%s  ",posfijo);
        printf ("\n");
	//system("PAUSE");
}


void in_a_pos (char *infijo,char *posfijo)
{
	struct LIFO pila;
	int i,j;
	char elemento;
	int operando (char c);
	int prioridad (char op1,char op2);
	char tope (struct LIFO p);
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,char s);
	void retira_pila (struct LIFO *p,char *s);
	i=0;
	j=-1;
	init_pila (&pila);
	while (infijo [i] != '#') {
	   if (operando (infijo [i]) )
		   posfijo [++j] = infijo [i++];
	   else {
		     while (!pila_vacia (&pila)  &&
			 prioridad (tope (pila),infijo [i] ) )  {
			     retira_pila (&pila,&elemento);
			     posfijo [++j] = elemento;
		      }
		      if (infijo [i] == ')')
			   retira_pila (&pila,&elemento);
		      else ins_pila (&pila,infijo [i]);
		      i++;
		}
	}
	while (!pila_vacia (&pila) ) {
		retira_pila (&pila,&elemento);
		posfijo [++j] = elemento;
	}
	posfijo [++j] = '\0';
}


int operando (char c)
{
	return ( c != '+' &&
		 c != '-' &&
		 c != '*' &&
		 c != '|' &&
		 c != '.' &&
		 c != ')' &&
		 c != '('    );
}

static int m[6][7] = {
	{ 1,1,0,0,0,0,1 },
	{ 1,1,0,0,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,1,0,1 },
	{ 0,0,0,0,0,0,0 }
};

int prioridad (char op1,char op2)
{
	int i,j;

	switch (op1) {
		case '+' :  i = 0; break;
		case '-' :  i = 1; break;
		case '*' :  i = 2; break;
		case '|' :  i = 3; break;
		case '.' :  i = 4; break;
		case '(' :  i = 5; break;
	}
	switch (op2) {
		case '+' :  j = 0; break;
		case '-' :  j = 1; break;
		case '*' :  j = 2; break;
		case '|' :  j = 3; break;
		case '.' :  j = 4; break;
		case '(' :  j = 5; break;
		case ')' :  j = 6; break;
	}
	return (m [i][j]);
}

char tope (struct LIFO p)
{
	return ( p.a [p.t -1] );
}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p,char s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,char *s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}

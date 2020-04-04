%{
       #include <stdio.h>
       #include <math.h>
       int yylex (void);
       void yyerror (char const *);
%}

     %define api.value.type {double}
     %token NUM

%%

input:
       %empty
     | input line
     ;

     line:
       '\n'
     | exp '\n'      { printf ("%.10g\n", $1); }
     ;

     exp:
       NUM
     | exp exp '+'   { $$ = $1 + $2;      }
     | exp exp '-'   { $$ = $1 - $2;      }
     | exp exp '*'   { $$ = $1 * $2;      }
     | exp exp '/'   { $$ = $1 / $2;      }
     | exp exp '^'   { $$ = pow ($1, $2); }  /* Exponentiation */
     | exp 'n'       { $$ = -$1;          }  /* Unary minus   */
     ;
%%

#include <ctype.h>

     int
     yylex (void)
     {
       int c = getchar ();
       /* Skip white space. */
       while (c == ' ' || c == '\t')
         c = getchar ();
       /* Process numbers. */
       if (c == '.' || isdigit (c))
         {
           ungetc (c, stdin);
           scanf ("%lf", &yylval);
           return NUM;
         }
       /* Return end-of-input. */
       else if (c == EOF)
         return 0;
       /* Return a single char. */
       else
         return c;
     }
int
     main (void)
     {
       return yyparse ();
     }
#include <stdio.h>

     /* Called by yyparse on error. */
     void
     yyerror (char const *s)
     {
       fprintf (stderr, "%s\n", s);
     }

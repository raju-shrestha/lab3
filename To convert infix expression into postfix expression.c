/*To convert infix expression into postfix expression
Auther: Raju shrestha
 Date:7th july 2016
Reference: Data structure book.
*/

include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100

typedef struct {
	int top;
	char items[MAXSIZE];
} stack ;

void push(stack *, char);
char pop(stack *);
void postfix(char *, char *);
int precedence(char, char);
int isdigit(int);
void popandtest(stack *, char *, int *);

main(){
	char infix[MAXSIZE];
	char postr[MAXSIZE];
	
	printf ("Enter an infix expression \n");
	gets(infix);
	
	printf ("Infix  Expression  = %s \n", infix);
	
	postfix(infix, postr);
	
	printf ("Postfix Expression = %s", postr);
	
	getch();
}

void push(stack *s, char x) {
	if (s->top == (MAXSIZE-1)){
		printf ("Stack Overflow \n");
		getch();
		exit(1);	
	} else {
		s->items[++(s->top)] = x;
	}
}

char pop(stack *s){
	if (s->top == -1){
		printf ("Stack Underflow \n");
		getch();
		exit (1);
	} else {
		return(s->items[s->top--]);
	}
}

void postfix(char infix[], char postr[]) {
	
	stack s;
	s.top = -1;
	char symb, topsymb = '+';
	int i = 0, und, outpos = 0;
	
	for (i = 0; (symb = infix[i]) != '\0'; i++) {
		
		if (isdigit(symb)) {
			postr[outpos++] = symb;
		} else {
			popandtest (&s, &topsymb, &und);
			while (!und && precedence(topsymb, symb)) {
				postr[outpos++] = topsymb;
				popandtest (&s, &topsymb, &und);
			}
		if (!und) {
			push (&s, topsymb);
		} 
		if (und || (symb != ')')) {
			push (&s, symb);
		} else {
			topsymb = pop(&s);
		}
	}
	}
	while (s.top != -1) {
		postr[outpos++] = pop(&s);
	}
		postr[outpos] = '\0';
		return;
}

int isdigit(int symb) {
	return (symb >= '0' && symb <= '9');
}

void popandtest(stack *s, char *x, int *und) {
	if (s->top == -1) {
		*und = 1;
		return;
	}
	*und = 0;
	*x = s->items[s->top--];
	return;
}

int precedence(char x, char y) {
	int z, p;
		
	switch (x) {
		case '(' : z = 0; break;
		case '$' : z = 3; break;
		case '*' : z = 2; break;
		case '/' : z = 2; break;
		case '+' : z = 1; break;
		case '-' : z = 1; break;
		default  : printf ("Error! \n");
	}
	switch (y) {
		case '(' : p = 9; break;
		case ')' : p = 0; break;
		case '$' : p = 3; break;
		case '*' : p = 2; break;
		case '/' : p = 2; break;
		case '+' : p = 1; break;
		case '-' : p = 1; break;
		default  : printf ("Error! \n");
	}
		
	return (z>p);
}

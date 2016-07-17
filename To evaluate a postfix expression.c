/*To evaluate a postfix expression
Auther: Raju shrestha
Date: 17th july 2016
Reference: Data structure book.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 50

typedef struct {
	int top;
	int items[MAXSIZE];
} stack ;

void push(stack *, int);
double pop(stack *);

int evaluate(char[]);
int isdigit(int);
int operation(int, int, int);

main(){
	char exp[50];
	
	printf ("Enter an expression \n");
	gets(exp);
	
	printf ("%s \n", exp);
	
	printf ("Result = %d", evaluate(exp));
	
	getch();
}

void push(stack *s, int x) {
	if (s->top == (MAXSIZE-1)){
		printf ("Stack Overflow \n");
		getch();
		exit(1);	
	} else {
		s->items[++(s->top)] = x;
	}
}

double pop(stack *s){
	if (s->top == -1){
		printf ("Stack Underflow \n");
		getch();
		exit (1);
	} else {
		return(s->items[s->top--]);
	}
}

int evaluate(char exp[]) {
	
	stack s;
	s.top = -1;
	int symb, operand1, operand2, value;
	int i = 0;
	
	while (exp[i] != '\0'){
		
		symb = exp[i];
		
		if (isdigit(symb)) {
			push (&s, (int) (symb-'0'));
		} else {
			operand2 = pop(&s);
			operand1 = pop(&s);
			
			value = operation(symb, operand1, operand2);
			
			push (&s, value);
		}
		i++;
	}
	return (pop(&s));
}

int isdigit(int symb) {
	return (symb >= '0' && symb <= '9');
}

int operation(int symb, int operand1, int operand2) {
	switch (symb) {
		case '+'	: return (operand1 + operand2);
		case '-'	: return (operand1 - operand2);
		case '*'	: return (operand1 * operand2);
		case '/'	: return (operand1 / operand2);
		case '$'	: return (pow(operand1, operand2));
		default 	: printf ("Invalid Operation! \n");
	}
}

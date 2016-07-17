/*To find if a mathematical expression is valid or not.
Auther: Raju shrestha
Date: 17th july 2016
Reference: Data structure book.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
	int top;
	char items[MAXSIZE];
} stack;

void push (stack *s, char);
char pop (stack *s);
void valid_not (char exp[]);
int ismatching_opener(char);

main ()
{
	char exp[100];
	
	printf ("Enter an expression \n");
	gets(exp);
	
	printf ("%s \n", exp);
	
	valid_not(exp);
	
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

void valid_not(char exp[]) {
	char symb, j;
	int valid = 1;
	
	stack s;
	s.top = -1;
	int i = 0;
	
	while (exp[i] != '\0'){
		
		symb = exp[i];
		
		if (symb == '(' || symb == '[' || symb == '{') {
			push(&s, symb);
		} 
		if (symb == ')' || symb == ']' || symb == '}') {
			if (s.top == -1) {
				valid = 0;
			} else {
				if (ismatching_opener(symb)) {
					valid = 0;
				}
			}
		}
		i++;
	}
	
	if (s.top != -1) {
		valid = 0;
	} 
	
	if (valid == 1) {
		printf ("The string is valid \n");
	} else {
		printf ("The string is not valid \n");
	}
}

int ismatching_opener(char symb) {
	
	stack s;
	int i;
	i = pop(&s);
	
	return ((symb == ')' && i != '(') || (symb == '}' && i != '{') || (symb == ']' && i != '['));
}

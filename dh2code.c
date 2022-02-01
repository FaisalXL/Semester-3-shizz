#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define size 20

int s[20];
int top = -1;
char infix[size], postfix[size];

void push(char n){
	if(top == size-1)
		printf("Stack Overflow.\n");
	else
		s[++top] = n;
}

char pop(){
	if(top == -1){
		printf("Stack underflow.\n");
		return 0;
	}
	char item = s[top];
	top--;
	return item;
}

int priority(char symbol){
	switch(symbol){
		case '#':
		return 0;
		case '(':
		return 1;
		case '+':
		case '-':
		return 2;
		case '*':
		case '/':
		return 3;
		case '$':
		case '^':
		return 4;
	}
}

void infixtopostfix(){
	char symbol;
	int j =0;
	push('#');
	for(int i = 0; i<strlen(infix); i++){
		symbol= infix[i];
		if(symbol == '(')
			push(symbol);
		else if(isalnum(symbol))
			postfix[j++]=symbol;
		else if(symbol == ')'){
			while(s[top]!='(')
				postfix[j++]= pop();
			top--;
		}
		else{
			while(priority(s[top]) >= priority(symbol))
				postfix[j++]= pop();
			push(symbol);
		}
	}
	while(s[top]!= '#')
		postfix[j++] = pop();
	postfix[j] = '\0';
}

void main(){
	printf("Enter a valid infix expression\n");
	scanf("%s", infix);
	
	infixtopostfix();
	
	printf("Given Infix expression:\t%s\n", infix);
	printf("Converted Postfix expression:\t%s\n", postfix);
}
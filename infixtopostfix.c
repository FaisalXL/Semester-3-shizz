#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 20

int stack[20];
int top = -1;
char infix[size];
char postfix[size];

void push(char n){
    if(top == size - 1)
       { printf("stack overflow\n");
        return;}
    else
        stack[++top] = n;
}

char pop(){
    if(top == -1){
        printf("stack underflow\n");
        return 0;
    }
    char element = stack[top];
    top--;
    return element;
}

int priority(char symbol){
    switch (symbol)
    {
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
    int j = 0;
    push('#');
    for(int i=0;i<strlen(infix);i++){
        symbol = infix[i];
        if(symbol == '(')
            push(symbol);
        else if(isalnum(symbol)){
            postfix[j++] = symbol;
        }
        else if(symbol == ')'){
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            top--;
        }
        else{
            while(priority(stack[top]) >= priority(symbol)){
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }
    while(stack[top] != '#'){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void main(){
    printf("Enter a valid infix expression to convert\n");
    scanf("%s",infix);

    infixtopostfix();

    printf("Given infix expression is \t%s\n",infix);
    printf("The posfix expression is: \t%s\n",postfix);
}
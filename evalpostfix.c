#include<stdio.h>
#include<ctype.h>

typedef struct stack{
    int top;
    int size;
    int array[20];
}stack;
stack* s1;

stack* create(int siz){
    s1 = (stack*) malloc(sizeof(stack));
    s1 ->size = siz;
    s1 ->top = -1;
    return s1;
}

void push(int n){
    s1 -> array[++s1->top] = n;
    printf("%d %d",n,s1 ->top);
}

int pop(){
    int element = s1 ->array[s1 -> top];
    s1 -> top--;
    printf("%d",s1->top);
    return element;
}

void postfix(){
    printf("enter a valid post fix operation\n");
    char lmao[20];
    scanf("%s",lmao);
    char* ptr = lmao;
    int size = 0;
    int i = 0;
    while(ptr[i] != '\0'){
        size++;
        printf("%d",size);
        i++;
    }
    s1 = create(size);
    ptr = lmao;
    i=0;
    while(ptr[i] != '\0'){
        if(isdigit(ptr[i])){
            printf("%d",ptr[i]-48);
            push(ptr[i]-48);
        }
        else{
            int v1 = pop();
            int v2 = pop();
            switch(ptr[i]){
                case '+':
                    push(v1+v2);
                    break;
                case '-':
                    push(v2-v1);
                    break;
                case '*':
                    push(v2*v1);
                    break;
                case '/':
                    push(v2/v1);
                    break;
            }
        }
        i++;
    }
    printf("the value of expression is %d", pop());
}

void main(){
    postfix();
}
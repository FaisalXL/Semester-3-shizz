#include <stdio.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack* head = NULL;

void push(int n){
    if(head == NULL){
        printf("Initializing Stack\n");
        printf("Entering firest element\n");
        struct stack* ptr = (struct stack*) malloc(sizeof(struct stack));
        ptr->data = n;
        ptr->next = NULL;
        head = ptr;
        return;
    }
    struct stack* ptr = (struct stack*) malloc(sizeof(struct stack));
    ptr->data = n;
    ptr->next = head;
    head = ptr;
    return;
}

void pop(){
    if (head == NULL)
    {
        printf("Stack Underflow\n");
    }
    struct stack* temp = (struct stack*) malloc(sizeof(struct stack));
    temp = head;
    head = head->next;
    free(temp);
}

void display(){
    if(head == NULL){
        printf("stack is empty\n");
        return;
    }
    struct stack* ptr = (struct stack*) malloc(sizeof(struct stack));
    ptr = head;
    printf("displaying stack elements");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void main(){
    printf("Programme for stack using linked list\n");
    int ch;
    int check = 0;
    while (check == 0)
    {
        printf("Please select your desired option\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("PLease enter data to push\n");
            int n;
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            check = -1;
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}


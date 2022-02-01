#include <stdio.h>
#define max 7
//stack follows LIFO.
//implemented here using simple array programme.
//we need push() to add to stack
//we need pop() to remove from stack

int front = -1;
int arr[max];

void push(int n){
    //to check if stack empty
    if (front == max - 1)
    {
        printf("\nStack Overflow\n");
        return;
    }
    else{
        ++front;
        arr[front] = n;
        printf("push successful");
    }
}

void pop(){
    if(front == -1){
        printf("\n Stack Underflow\n");
    }
    else
    {
        front--;
        printf("\n Pop successful");
    }
}

void display(){
    //to display the stack
    printf("The current Stack is: \n");
    for (int i = front; i >= 0; i--)
    {
        printf("%d ", arr[i]);
        
    }
    
}


void main(){
    
    int ch;
    int n;
    int check = 0;
    while(check == 0){
        printf("\nSelect the desired operations\n");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        
        scanf("%d",&ch);
        
        switch (ch)
        {
        case 1:
            printf("\n Enter the element to be pushed");
            scanf("%d", &n);
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
            printf("invalid choice");
            break;
        }
    }


}
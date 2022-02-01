#include<stdio.h>
#define max 5
//queue follows FIFO
//implemented here in this code using array
//we need enqueue to add to queue
//we need dequeue to remove from queue

int front = -1;
int rear = -1;
int arr[max];

void enqueue(int n){
    if (rear == -1) 
    {
        front = 0;
        rear = 0;
        printf("Initializing Queue\n");
        arr[rear] = n;
    }
    else if (rear == max -1)
    {
        printf("\nQueue full\n");
        return;
    }
    else
    {
        rear++;
        arr[rear] = n;
    }
}

void dequeue(){
    if (rear == -1)
    {
        printf("\nqueue empty\n");
    }
    else{
        front++;
        if (front>rear)
        {
            front = -1;
            rear = -1;
        }
        
    }
}

void display(){
    if(rear == -1){
        printf("\nQueue empty");
    }
    else
    {
        printf("\nThe Queue is:\n");
        for(int i = front;i<=rear;i++){
            printf("%d ", arr[i]);
        }
    }
}

void main(){
    int ch;
    int n;
    int check = 0;
    while(check == 0){
        printf("\nSelect the desired operations\n");
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.display");
        printf("\n4.exit");

        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to be enqueued");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            check = -1;
        default:
            printf("Invalid choice");
            break;
        }
    }

}
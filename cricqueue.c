#include <stdio.h>
//circular queue are like queues but circular
//they follow the same fifo rule but they are more versatile
#define size 5

int arr[size];
int front = -1;
int rear = -1;

void enqueue(int n){
    if((front == 0 && rear == size -1) || front == rear + 1 ){
        printf("The queue is full, please try again\n");
        return;
    }
    if(front == -1){
        printf("initializing new queue\n");
        front = 0;
        rear = 0;
        arr[rear] = n;
        return;
    }
    rear = (rear + 1)%size;
    arr[rear] = n;
}

void dequeue(){
    if(front == -1){
        printf("queue empty soz\n");
        return;
    }
    if(front == rear){
        printf("dequeing the last element from the queue\n");
        front = -1;
        rear = -1;
        return;
    }
    front = (front + 1)%size;
}

void display(){
    if(front == -1){
        printf("queue is empty bruh soz\n");
        return;
    }
    printf("displaying the queue\n");
    int i =0;
    for( i = front; i!= rear; i =(i+1)%size){
        printf("%d ",arr[i]);
    }
    printf("%d",arr[i]);
    printf("\n");
}

void main(){
    printf("programme to show circular queue\n");
    int n;
    int check = 0;
    while(check == 0){
        printf("please select your desired options\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("enter the element you want to enqueue\n");
            int el;
            scanf("%d",&el);
            enqueue(el);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            check = -1;
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }

} 

#include<stdio.h>

struct queue{
    int data;
    struct queue* next;
};

struct queue* head = NULL;
struct queue* tail = NULL;

void enqueue(int n){
    if(head == NULL){
        printf("initializing queue\n");
        printf("Entering first element in queue\n");
        struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
        temp->data = n;
        temp->next = NULL;
        head = temp;
        tail = temp;
        return;
    }
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp ->data = n;
    temp ->next = NULL;
    tail->next = temp;
    tail = temp;
}

void dequeue(){
    if(head == NULL){
        printf("Queue is Empty\n");
        return;
    }
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp = head;
    head = head->next;
    free(temp);
}

void display(){
    if(head == NULL){
        printf("queue is empty\n");
        return;
    }
    printf("Displaying queue\n");
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp ->next;
    }
    printf("\n");
}

void main(){
    printf("Programme to implement queue\n");
    int ch;
    int check = 0;
    while (check == 0)
    {
        printf("please enter desired choice\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");

        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("PLease enter data to enqueue\n");
            int n;
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
            break;
        default:
            printf("invalid chocie\n");
            break;
        }
    }
    
}
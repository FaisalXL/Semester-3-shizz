#include<stdio.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

node* head = NULL;
node* tail = NULL;
node* ptr;
node* temp;
node* bef;
node* after;
node* min;

node* createNode(){
    int n;
    printf("Enter data for new node");
    scanf("%d",&n);
    node* new = (node*) malloc(sizeof(node));
    new ->data =n;
    new ->next = NULL;
    new ->prev = NULL;
    return new;
}

node* search(int n){
    if(head == NULL){
        return NULL;
    }
    ptr = head;
    while(ptr != NULL){
        if(ptr->data == n){
            break;
        }
        ptr = ptr -> next;
    }
    return ptr;
}

void insertAny(){
    if(head == NULL){
        ptr = createNode();
        printf("entering first node\n");
        head = ptr;
        tail = ptr;
        return;
    }
    node* newnode = (node*) malloc(sizeof(node));
    newnode = createNode();
    //printf("value of new node %d",newnode ->data);
    printf("enter data of node around which you want to insert\n");
    int data;
    scanf("%d",&data);
    temp = search(data);
    if(temp == NULL){
        printf("node not found, please try again\n");
        return;
    }
    printf("do you want to insert before or after the node?\n1.Before\n2.After\n");
    int check;
    scanf("%d",&check);
    if(check == 1){
        if(temp -> prev == NULL){
            printf("Entering before head node\n");
            head -> prev = newnode;
            newnode -> next = head;
            head = newnode;
            //printf("head ptr val %d",head ->data);
            return;
        }
        bef = temp ->prev;
        bef ->next = newnode;
        newnode ->prev = bef;
        newnode ->next = temp;
        temp -> prev = newnode;
        return;
    }
    if(check == 2){
        if(temp->next == NULL){
            printf("entering after tail node\n");
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
            return;
        }
        after = temp -> next;
        temp -> next = newnode;
        newnode -> prev = temp;
        newnode -> next = after;
        after -> prev = newnode;
        return; 
    }
}

void deleteAny(){
    printf("enter the node you want to remove\n");
    int n;
    scanf("%d",&n);
    ptr = search(n);
    if(ptr == NULL){
        printf("node does not exist, please try again\n");
        return;
    }
    //would have to maybe add for last remianing element in the list
    if(ptr -> prev == NULL){
        printf("deleting first node\n");
        head = ptr ->next;
        head ->prev = NULL;
        free(ptr);
        return;
    }
    if(ptr -> next == NULL){
        printf("deleting last node\n");
        tail = ptr -> prev;
        tail -> next = NULL;
        free(ptr);
        return;
    }
    bef = ptr ->prev;
    after = ptr ->next;
    bef ->next = after;
    after ->prev = bef;
    free(ptr);
}

void display(){
    if(head == NULL){
        printf("the list is empty\n");
        return;
    }
    printf("displaying the list\n");
    ptr = head;
    while(ptr!= NULL){
        printf("the data in the node is %d", ptr->data);
        ptr = ptr -> next;
    }
}

void main(){
    printf("welcome to doubly linked lists\n");
    int ch;
    int check = 0;
    while(check == 0){
        printf("please enter your desired choice\n1.search\n2.insert\n3.delete\n4.display\n5.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter the data of node you want to search\n");
                int n;
                scanf("%d",&n);
                min = search(n);
                if(min == NULL){
                    printf("element not found, please try again\n");
                }
                else{
                    printf("element found , data: %d",min->data);
                }
                break;
            case 2:
                insertAny();
                break;
            case 3:
                deleteAny();
                break;
            case 4:
                display();
                break;
            case 5:
                check = 1;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
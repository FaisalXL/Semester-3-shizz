#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    int value;
}*head , *ptr;

struct node* recurse(){
    int value1;
    printf("enter value or -1 to end\n");
    scanf("%d" , &value1);
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if( value1 != -1){
        //struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->value = value1;
        ptr->next = recurse();
    }
    else{
        return head;
    }
    return ptr;
}

void display(){
    if (head==NULL){
        printf("no elements\n");
    }
    else{
        ptr = head;
        while(ptr->next != head){
            printf("%d\t",  ptr->value);
            ptr = ptr->next;
        }
        printf("%d" , ptr->value);
    }
}

void main(){
    int choice , value;
    head = (struct node*)malloc(sizeof(struct node));
    printf("enter value of first node\n");
    scanf("%d" , &head->value);
    head->next = recurse();
    while(1){
        printf("\n1.display\n2.exit\n");
        scanf("%d" , &choice);
        switch(choice){
        case 1:
            display();
            break;
        case 2:
            exit(0);
            break;
        }
        
    } 
    
}
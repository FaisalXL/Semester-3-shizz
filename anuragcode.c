#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    int value;
}*head , *ptr;


struct node* create(int value){
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

struct node* recurse(struct node *ptr){
    int value;
    printf("enter value and -1 to end\n");
    scanf("%d" , &value);
    if( value != -1){
        ptr = create(value);
        ptr->next = recurse(ptr);
    }
    else{
        ptr->next = head;
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
            printf("%d",  ptr->value);
            ptr = ptr->next;
        }
        printf("%d" , ptr->value);
    }
}

void main(){
    int choice;
    head = NULL;
    recurse(head);
    
}
#include<stdio.h>
#include<string.h>
//linked list programme insert anywhere and delete anywhere

typedef struct linkedlist{
    int data;
    struct linkedlist* next;
}link;

link* head = NULL;
link* trick = NULL;

link* search(int n){
    if(head == NULL){
        printf("the linked list is empty, search aborted\n");
        return NULL;
    }
    link* temp = (link*) malloc(sizeof(link));
    temp = head;
    while(temp != NULL){
        if(temp->data == n){
            break;
        }
        temp = temp -> next;
    }
    //printf("not found\n");
    return temp;
}

link* createNode(int n){
    link* new = (link*) malloc(sizeof(link));
    new->data = n;
    new->next = NULL;
    return new;
}

void insertAny(int n){
    if(head == NULL){
        printf("inserting first node\n");
        link* trace = (link*) malloc(sizeof(link));
        trace = createNode(n);
        head = trace;
        return;
    }
    printf("Enter data of Node around which you want to add new Node\n");
    int src;
    scanf("%d",&src);
    link* temp = (link*) malloc(sizeof(link));
    temp = search(src);
    link* ptr = (link*) malloc(sizeof(link));
    ptr = createNode(n);
    if(temp == NULL){
        printf("Node not found, please try again\n");
        return;
    }
    int check;
    printf("Do you want to enter the new Node before the Node or after the Node\n1.Before\n2.After\n");
    scanf("%d",&check);
    if(check == 1){
        printf("adding new node before the selected node\n");
        if(temp == head){
            printf("Entering before head node\n");
            ptr ->next = head;
            head = ptr;
            return;
        }
        link* before = (link*) malloc(sizeof(link));
        while(before->next != temp){
            before = before ->next;
        }
        before ->next = ptr;
        ptr ->next = temp;
        return;
    }
    else if(check == 2){
        printf("adding node after theselected node\n");
        if(temp->next == NULL){
            printf("Adding after the last node\n");
            temp ->next = ptr;
            return;
        }
        link* after = (link*) malloc(sizeof(link));
        after = temp -> next;
        temp -> next = ptr;
        ptr -> next = after;
        return;
    }
}

void deleteAny(){
    printf("please enter the data of the node you want to delete\n");
    int data;
    scanf("%d",&data);
    link* del = (link*) malloc(sizeof(link));
    del = search(data);
    if(del == NULL){
        printf("node not found, please try again\n");
        return;
    }
    if(del == head){
        printf("deleting head node\n");
        head = head ->next;
        free(del);
        return;
    }
    if(del ->next == NULL){
        printf("deleting last node\n");
        link* before = (link*) malloc(sizeof(link));
        before = head;
        while(before->next != del){
            before = before->next;
        }
        before->next = NULL;
        free(del);
        return;
    }
    else{
        printf("deleting node from the middle of the linked list\n");
        link* before = (link*) malloc(sizeof(link));
        before = head;
        while(before->next != del){
            before = before->next;
        }
        before -> next = del -> next;
        free(del);
        return;
    }
}

void display(){
    if(head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    link* ptr = (link*) malloc(sizeof(link));
    ptr = head;
    while(ptr != NULL){
        printf("The data stored in the node is %d \n The address of the node is %x",ptr->data,ptr);
        ptr = ptr->next;
    }
}

void main(){
    printf("welcome to linked list programme\n");
    int check = 0;
    int ch;
    while(check == 0){
        printf("please enter the desired choice\n");
        printf("1.Search\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter element to search\n");
            int n;
            scanf("%d",&n);
            trick = search(n);
            if(trick == NULL){
                printf("node not found\n");
            }
            else{
                printf("node found\nnode data: %d",trick ->data);
            }
            break;
        case 2:
            printf("enter data for a node to be insert\n");
            int dat;
            scanf("%d", &dat);
            insertAny(dat);
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
            printf("invalid choice\n");
            break;
        }
    }
}
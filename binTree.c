//(create,insert), delete , display ( inorder )
#include <stdio.h>

typedef struct binaryTree{
    int data;
    struct binaryTree* left;
    struct binaryTree* right;
}BST;

BST* root = NULL;
BST* createTree(BST* root,int n){
    if(root == NULL){
        //printf("creating binary search tree\n");
        printf("entering node\n");
        //printf("enter the data you want to put in\n");
        //scanf("%d",&n);
        root = (BST*) malloc(sizeof(BST));
        root ->data = n;
        root ->left = root ->right = NULL;
    }
    else{
        //BST* ptr;
        if(n<root->data){
            root->left = createTree(root->left,n);
        }
        if(n>root->data){
            root->right = createTree(root->right,n);
        }       
        //ptr = (BST*) malloc(sizeof(BST));

    }
    return root;
}

BST* delete(BST* root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(data < root->data){
        root -> left = delete(root -> left,data);
    }
    else if(data > root->data){
        root -> right = delete(root->right,data);
    }
    else{
        //case1:
        if(root->left == NULL && root->right == NULL){
            BST* temp;
            temp = root;
            root = NULL;
            free(temp);
        }
        else if(root -> left == NULL){
            BST* temp;
            temp = root;
            root = root -> right;
            free(temp);
        }
        else if(root->right == NULL){
            BST* temp;
            temp = root;
            root = root ->left;
            free(temp);
        }
        else{
            BST* ptr = root -> right;
            while(ptr->left!= NULL){
                ptr = ptr -> left;
            }
            root ->data = ptr -> data;
            root -> right = delete(root->right,ptr->data);
        }
    }
    return root;
}

void display(BST* root){
    if(root == NULL){
        return;
    }
    display(root->left);
    printf("%d \t",root->data);
    display(root->right);
}


int main(){
    printf("1.Create Binary Tree\n2. Delete\n3. InOrder Display\n4. Exit\n");
    int choice;
    while(1){
        printf("\nEnter choice\t");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int n=0;
                printf("enter the data you want to put in\n");
                scanf("%d",&n);
                root = createTree(root,n);
                break;
            case 2:
                printf("Enter the data of node to be deleted: \n");
                int nig;
                scanf("%d",&nig);
                root = delete(root, nig);
                break;
            case 3:
                printf("InOrder tree traversal\n");
                display(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
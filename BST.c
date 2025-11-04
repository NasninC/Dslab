#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *left;
        struct Node *right;
};
struct Node* createNode(int value){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->left=newNode->right=NULL;
        return newNode;
}
struct Node*insert(struct Node*root,int value){
        if(root==NULL){
                root=createNode(value);
        }else if(value<root->data){
                root->left=insert(root->left,value);
        }else if(value>root->data){
                root->right=insert(root->right,value);
        }else{
                printf("Duplicate value not allowed!\n");
        }
                return root;
}
struct Node* search(struct Node* root,int key){
        if(root==NULL || root->data == key)
                return root;
        if(key<root->data)
                return search(root->left,key);
        else
                return search(root->right,key);
}
void inorder(struct Node* root){
        if(root!=NULL){
                inorder(root->left);
                printf("%d",root->data);
                inorder(root->right);
        }
}
void preorder(struct Node* root){
        if(root!=NULL){
                printf("%d",root->data);
                preorder(root->left);
                preorder(root->right);
        }
}
void postorder(struct Node* root){
        if(root!=NULL){
                postorder(root->left);
                postorder(root->right);
                printf("%d",root->data);
        }
}
struct Node* findMin(struct Node* root){
        while(root->left!=NULL)
                root=root->left;
        return root;
}
struct Node* deleteNode(struct Node* root,int key){
        if(root==NULL)
                return root;
        if(key<root->data)
                root->left=deleteNode(root->left,key);
        else if(key>root->data)
                root->right=deleteNode(root->right,key);
else{
                if(root->left==NULL){
                        struct Node* temp=root->right;
                        free(root);
                        return temp;
                }else if(root->right==NULL){
                        struct Node* temp=root->left;
                        free(root);
                        return temp;
                }
                struct Node* temp=findMin(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
        }
        return root;
}
int main(){
        struct Node* root=NULL;
        int choice,value;
        while(1){
                printf("\n---Binary Search Tree(BST) Operations---\n");
                printf("1.Insert node\n");
                printf("2.Search node\n");
                printf("3.Inorder Traversal\n");
                printf("4.Preorder Traversal\n");
                printf("5.Postorder Traversal\n");
                printf("6.Delete Node\n");
                printf("7.Exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
printf("Enter value to insert:");
                                scanf("%d",&value);
                                root=insert(root,value);
                                break;
                        case 2:
                                printf("Enter value to search:");
                                scanf("%d",&value);
                                if(search(root,value))
                                        printf("%d found in the tree.\n",value);
                                else
                                        printf("%d not found in the tree.\n",value);
                                break;
                        case 3:
                                printf("Inorder Traversal:");
                                inorder(root);
                                printf("\n");
                                break;
                        case 4:
                                printf("Preorder Traversal:");
                                preorder(root);
                                printf("\n");
                                break;
                        case 5:
                                printf("Postorder Traversal:");
                                postorder(root);
                                printf("\n");
                                break;
                        case 6:
                                printf("Enter value to delete:");
                                scanf("%d",&value);
                                root=deleteNode(root,value);
                                printf("Node deleted (if it existed).\n");
break;
                        case 7:printf("Exiting program...\n");
                               exit(0);
                        default:
                               printf("Invalid choice!Please try again.\n");
                }
        }
        return 0;
}

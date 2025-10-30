#include<stdio.h>
#define MAX 100
int parent[MAX];
void makeSet(int n){
        for(int i=0;i<n;i++){
                parent[i]=i;
        }
}
int find(int x){
        if(parent[x]==x)
        return x;
        else
        return find(parent[x]);
        }
void unionSet(int x,int y){
        int parentX=find(x);
        int parentY=find(y);
        if(parentX!=parentY){
                parent[parentY]=parentX;
                printf("Joined %d and %d \n",x,y);
        }else{
                printf("%d and %d are already in the same set \n",x,y);
        }
}
void display(int n){
        printf("Parent array:");
        for(int i=0;i<n;i++){
                printf(" %d ",parent[i]);
        }
        printf("\n");
}
int main(){
        int n,choice,x,y;
printf("Enter number of elements:");
        scanf("%d",&n);
        makeSet(n);
        do{
                printf("\n---Disjoint set operations---\n");
                printf("1.Union\n");
                printf("2.Find\n");
                printf("3.Display parent array\n");
                printf("4.Exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("Enter two elements to union:");
                                scanf("%d %d",&x,&y);
                                unionSet(x,y);
                                break;
                        case 2:
                                printf("Enter elements to find its representation:");
                                scanf("%d",&x);
                                printf("Representative of %d is %d\n",x,find(x));
                                break;
                        case 3:
                                display(n);
                                break;
                        case 4:
                                printf("Exiting...\n");
                                break;
                        default:
                                printf("Invalid choice!\n");
                }
 }
        }while(choice!=4);
        return 0;
}


#include<stdio.h>
  int createBitString(int set[],int size,int u[],int n){
  int bitString=0;
   for(int i=0;i<size;i++){
     for(int j=0;j<n;j++){
        if(set[i]==u[j]){
   bitString|=(1<<(n-j-1));
        }
     }
   }
   return bitString;
  }
void displaySet(int bitString,int u[],int n){
        int empty=1;
        printf("{");
        for(int i=0;i<n;i++){
                if(bitString&(1<<(n-i-1))){
                        printf("%d",u[i]);
                        empty=0;
                }
        }
        if(empty)
                printf("%d");
        printf("}\n");
}
int main(){
        int n,sizeA,sizeB,choice;
        int u[20],A[20],B[20];
        int bitA,bitB,bitU,result;
        printf("Enter size of universal set:");
        scanf("%d",&n);
        printf("Enter elements of universal set:");
for(int i=0;i<n;i++)
                scanf("%d",&u[i]);
        printf("Enter number of elements in set A:");
        scanf("%d",&sizeA);
        printf("Enter elements of set A:");
        for(int i=0;i<sizeA;i++)
                scanf("%d",&A[i]);
        printf("Enter number of elements in set B:");
        scanf("%d",&sizeB);
        printf("Enter elements of set B:");
        for(int i=0;i<sizeB;i++)
                scanf("%d",&B[i]);
        bitA=createBitString(A,sizeA,u,n);
        bitB=createBitString(B,sizeB,u,n);
        bitU=(1<<n)-1;
        while(1){
                printf("\n---Set Operations Menu---\n");
                printf("1.Union(AUB)\n");
                printf("2.Intersection(AnB)\n");
                printf("3.Difference(A-B)\n");
                printf("4.Complement of A(U-A)\n");
                printf("5.Exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                if(choice==5){
                        printf("Exiting program...\n");
                        break;
                }
                switch(choice){
                        case 1:
result=bitA|bitB;
                                printf("AUB=");
                                displaySet(result,u,n);
                                break;
                        case 2:
                                result=bitA&bitB;
                                printf("AnB=");
                                displaySet(result,u,n);
                                break;
                        case 3:
                                result= bitA&(~bitB);
                                printf("A-B=");
                                displaySet(result,u,n);
                                break;
                        case 4:
                                result=bitU&(~bitA);
                                printf("U-A=");
                                displaySet(result,u,n);
                                break;
                        default:
                                printf("Invalid choice!Try again..\n");
                }
        }
        return 0;
}

#include<stdio.h>
int main(){
int arr1[50],arr2[50],merged[100];
int n1,n2,i,j,k;
printf("Enter number of elements in first:\n");
scanf("%d",&n1);
printf("Enter elements in the first:\n");
for(i=0;i<n1;i++){
scanf("%d",&arr1[i]);
}
printf("Enter number of elements in the second:");
scanf("%d",&n2);
printf("Enter elements in the second:\n");
for(i=0;i<n2;i++){
scanf("%d",&arr2[i]);
}
for(i=0;i<n1;i++){
merged[i]=arr1[i];
}
for(j=0;j<n2;j++){
merged[i+j]=arr2[j];
}
printf(" Merged array :");
for(k=0;k<n1+n2;k++){
printf(" %d ",merged[k]);
}
return 0;
}

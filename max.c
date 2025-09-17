#include<stdio.h>
int main(){
int arr[6],max;
printf("Enter array elements:");
for(int i=0;i<6;i++){
scanf("%d",&arr[i]);
}
max=arr[0];
for(int i=1;i<5;i++)
{
if(arr[i]>max){
max=arr[i];
}
}
printf("The maximum element in the array is: %d \n",max);
return 0;
}

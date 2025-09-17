#include<stdio.h>
#include<stdlib.h>
#define n 5
int main()
{
int queue[n],ch=1,front=0,rear=0,i,j=1,x=n;
printf("Queue using array");
printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
while(ch){
printf("\n Enter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
if(rear==x){
printf("\n Queue is full");
}
else{
printf("Enter number %d:",j++);
scanf("%d",&queue[rear++]);
}
break;
case 2:
if(front==rear)
{
printf("\n Queue is empty");
}
else{
printf("\n Deleted element is %d",queue[front++]);
x++;
}
break;
case 3:
printf("\n Queue elements are:\n");
if(front==rear){
printf("\n Queue is empty");
}
else{
for(i=front;i<rear;i++)
{
printf("%d",queue[i]);
printf("\n");
}
break;
case 4:
exit(0);
default:
printf("Wrong choice:please see the options");
}}}
return 0;
}

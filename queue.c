#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};

typedef struct node *NODE; /* Node Pointer for NODE structure*/
NODE getnode()
{
NODE x ;
x = (NODE)malloc(sizeof(struct node)); /* Create NODE dynamically*/
if(x==NULL)
{
printf("out of memory\n");
exit(0);
}
/* Initially NODE link is set to NULL*/
return x; /* return NODE Pointer */
}
NODE insert_rear(int item,NODE first)
{
NODE temp;
NODE cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
return temp;
cur=first;
while(cur->link!=NULL)
{
cur=cur->link;
}
cur->link=temp;
return first;
}
NODE delete_front(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("List is Empty\n");
return NULL;
}
temp=first;
temp=temp->link;
printf("item deleted =%d",first->info);

printf("Front node deleted successfully\n");
free(first);
return temp;
}
void display(NODE first)
{
NODE cur;
if(first == NULL)
{
printf("List is Empty\n");
return;
}
printf("The contents of singly linked list are\n");
cur=first;
while(cur!=NULL)
{
printf("%d\t",cur->info);
cur=cur->link;
}
printf("\n");
}
void main()
{
NODE first;
int ch ,item,key,i,n;
first=NULL;
while (1)
{
printf("\n**********Singly Linked List Operations Menu**********\n");
printf("1. insert_rear 3.Delete_Front\n");
printf("2:Display  4.exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
switch (ch)
{
case 1:printf("Enter a node to insert towards front of SLL\n");
printf("enter the item to be inserted\n");
scanf("%d",&item);
first=insert_rear(item,first);
    break;
case 2: display(first);
    break;  
case 3:
    first=delete_front(first);
    break;
case 4:exit(0);
}
}
}

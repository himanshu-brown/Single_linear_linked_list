#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct lklist    //Self referential structure
{
 int info;
 struct lklist *next;
}node;
void main()
{
 int choice,item,position;
 void insert_at_beginning(node **,int);
 void insert_at_end(node **,int);
 void insert_at_after_element(node **,int,int);
 void traversing(node *);
 void traversing_in_rev_order(node *);
 void searching(node *,int);
 void delete_at_beg(node**);
 void delete_at_end(node **);
 void delete_entire_list(node **);
 void delete_at_nth_position(node **,int);
 node *head; //Starting pointer to point first node of linked list
 head=NULL; //Creation of empty linked list
 while(1)
 {
  clrscr();
  printf("SINGLE LINEAR LINKED LIST\n");
  printf("-------------------------\n");
  printf("1. Insert at begenning \n");
  printf("2. Insert at end \n");
  printf("3. Insert at after element \n");
  printf("4. Searching \n");
  printf("5. Traversing \n");
  printf("6. Traversing in reverse order \n");
  printf("7. Delete at beg \n");
  printf("8. Delete at end \n");
  printf("9. Delete an element at nth position \n");
  printf("10. Delete entire list \n");
  printf("11. Exit \n");
  printf("Enter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: //Insert at beginning
	printf("Here we insert an element at beginning \n");
	printf("Enter the item : ");
	scanf("%d",&item);
	insert_at_beginning(&head,item);
	printf("Insertion successfully");
	break;
   case 2: //Insert at end
	printf("Here we insert an element at end \n");
	printf("Enter the item : ");
	scanf("%d",&item);
	insert_at_end(&head,item);
	printf("Insertion successfully");
	break;
   case 3: //Insert at after element
	printf("Here we insert an element after element \n");
	printf("Enter after which you want to insert an element in linked list :");
	scanf("%d",&position);
	printf("Enter the item : ");
	scanf("%d",&item);
	insert_at_after_element(&head,position,item);
	printf("Insertion successfully");
	break;
   case 4: //Searching
	printf("Enter which element you want to search in linked list : ");
	scanf("%d",&item);
	searching(head,item);
	break;
   case 5: //Traversing
	traversing(head);
	break;
   case 6: //Traversing in reverse order
	traversing_in_rev_order(head);
	break;
   case 7: //Delete at beg
	delete_at_beg(&head);
	break;
   case 8: //Delete at end
	delete_at_end(&head);
	break;
   case 9: //Delete an element at nth position
	printf("On which position you want to delete an element : ");
	scanf("%d",&position);
	delete_at_nth_position(&head,position);
	break;
   case 10: //Delete entire list
	delete_entire_list(&head);
	break;
   case 11:
	exit(0);
  }
  getch();
 }
}
void insert_at_beginning(node **head,int item)
{
 node *loc;
 loc=(node *)malloc(sizeof(node));
 loc->info=item;
 if(*head==NULL)
 loc->next=NULL;
 else
 loc->next=*head;
 *head=loc;
}
void traversing(node *head)
{
 node *loc;
 loc=head;
 while(loc!=NULL)
 {
  printf("%d  ",loc->info);
  loc=loc->next;
 }
}
void traversing_in_rev_order(node *head)
{
 if(head==NULL)
 return;
 else
 {
  traversing_in_rev_order(head->next);
  printf("%d ",head->info);
 }
}
void insert_at_end(node **head,int item)
{
 node *loc,*ptr;
 ptr=(node *)malloc(sizeof(node));
 ptr->info=item;
 ptr->next=NULL;
 if(*head==NULL)
 *head=ptr;
 else
 {
  for(loc=*head;loc->next!=NULL;loc=loc->next);
  loc->next=ptr;
 }
}
void insert_at_after_element(node **head,int position,int item)
{
 node *ptr,*loc;
 ptr=NULL;
 for(loc=*head;loc->next!=NULL;loc=loc->next)
 {
  if(loc->info==position)
  {
   ptr=(node*)malloc(sizeof(node));
   ptr->info=item;
   ptr->next=loc->next;
   loc->next=ptr;
  }
 }
 if(ptr==NULL)
 printf("Element not found");
}
void searching(node *head,int item)
{
 while(head!=NULL && head->info!=item)
 head=head->next;
 if(head->info==item)
 printf("Element found");
 else
 printf("Element not found");
}
void delete_at_beg(node **head)
{
 node *loc,*ptr;
 if(*head==NULL)
 return;
 else
 {
  loc=*head;
  *head=(*head)->next;
  free(loc);
 }
}
void delete_at_end(node **head)
{
 node *loc,*ptr;
 if(*head==NULL)
 return;
 else if((*head)->next==NULL)
	{
	 loc=*head;
	 *head=NULL;
	 free(loc);
	}
	else
	{
	 loc=*head;
	 ptr=(*head)->next;
	 while(ptr->next!=NULL)
	 {
	  loc=ptr;
	  ptr=ptr->next;
	 }
	 loc->next=NULL;
	 free(ptr);
	}
}
void delete_at_nth_position(node **head,int position)
{
 node *loc,*prev,*ptr;
 int i,count=0;
 if(*head==NULL)
 return;
 loc=*head;
 if(position==1)
 {
  *head=(*head)->next;
  free(loc);
  return;
 }

 while(loc->next!=NULL)
 {
  count++;
  loc=loc->next;
 }
 loc=*head;
 count++;
 if(count==position)
 {
  ptr=(*head)->next;
	 while(ptr->next!=NULL)
	 {
	  loc=ptr;
	  ptr=ptr->next;
	 }
	 loc->next=NULL;
	 free(ptr);
  return;
 }
 for(i=1;i<=position-1;i++)
 {
  prev=loc;
  loc=loc->next;
 }
 prev->next=loc->next;
 free(loc);
}
void delete_entire_list(node **head)
{
 node *loc;
 while(*head!=NULL)
 {
  loc=*head;
  *head=(*head)->next;
  free(loc);
 }
}
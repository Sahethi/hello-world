/*
Micro Project on DSU (Data Structures) CO3I
Topic: Implementation of Priority Queue using Linked List.
Students 1)Mihir Chichria 7
	 2)Chiraj Matai 8
	 3)Sahethi Depuru Guru 9
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NULL 0
/*
Below we are creating a structure Node whose members are:-
1)A pointer next which is used for poiting towards next node in linked list.
2)int priority which accepts the priority of the data entered by the
user as it is a priority queue.
3)char name is the data which is being stored in the linked list.
*/
struct Node
{
	struct Node *next;
	int priority;
	char name[25];
}
;
//Pointer first is the head node of the linked list, which is initially NULL.
struct Node *first=NULL;
/*
Function: create() is used to insert values into the link list from rear
just like in the queue.
Parameters: 1)pointer pnode stores the value of the new node entered into
	      the linked list.
	    2)pointer current is used to store the value of ongoing node.
	    3)**x is use for sorting the program while inserting the data
	      into the list.
Return Type: void
*/
void create()
{
	struct Node *pnode,*current,**x;
	char ch;
	do
	{
		pnode=(struct Node*)malloc(sizeof(struct Node));
		if(pnode==NULL)//checking whether the memory is available.
		{
			printf("\nMemory Overflow!! Cannot create list.");
			break;
		}
		//accepting name and priority
		printf("\nEnter the Priority:- ");
		scanf("%d",&pnode->priority);
		printf("\nEnter the Name:- ");
		scanf("%s",&pnode->name);
		if(first==NULL) //for inserting first element
		{
			first=pnode;
			pnode->next=NULL;
		}
		else
		{
			current=first;
			x=&first;
			while(current!=NULL && current->priority<pnode->priority)
			{
				x=&current->next;//storing the address of current's next
				current=current->next;//current moving ahead
			}
			/*
			When current's priority is more than pnode's
			priority then we are inserting the element before
			current when x is pointing towards pnode and
			pnode is pointing to current.
			*/
			*x=pnode;
			pnode->next=current;
		}
		printf("\nNode Inserted Succesfully!!");
		printf("\nDo you wish to continue? (y/n) ");
		scanf("%s",&ch);
      }while(ch=='y'||ch=='Y');
}
/*
Function: deleteFromFront() it is used to delete the element from the linked
list with the highest priority from front just like a queue.
Parameters: 1)pointer follow is used to point to the previous node of current
	      initially starting from 1.
Return Type: void
*/
void deleteFromFront()
{
	struct Node *current,*follow;
	if(first==NULL)//checking whether the list is empty.
		printf("\nList is Empty.");
	else
	{
		current=first;
		first=current->next;
		printf("\nDeleted Priority %d and Name %s",current->priority,current->name);
		free(current);//freeing the memory of current;
	}

}
/*
Function: display() function is used in order to show the elements in this
linked list which is working like a priority queue.
Return Type: void
*/
void display()
{
	struct Node *current;
	if(first==NULL)//checking whether the list is empty.
		printf("\nList is Empty.");
	else
	{
		current=first;//initially current is first.
		printf("\nList is: ");
		while(current!=NULL)//loop will run till current is not NULL.
		{
			printf("\nPriority %d and Name %s",current->priority,current->name);
			current=current->next;//current is moving ahead.
		}
	}
}// end of display function.
/*
Main function is just displaying the different functions of the program
which are making a linked list work like a priority queue.
Parameters: int ch is accepting the choice from the user by asking him
whether he wants to insert, delete, display or exit.
*/
void main()
{
	clrscr();
	create();
	int ch;
	while(1)
	{
		printf("\n=====Menu=====");
		printf("\n1.Display the elements in the Queue.\n2.Delete an element from the Queue.\n3.Insert an element into the Queue.\n4.Exit");
		printf("\nEnter your choice:- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				display();
				break;
			case 2:
				deleteFromFront();
				break;
			case 3:
				create();
				break;
			case 4:
				exit(0);
		}//end of switch
	}//end of while
}//end of main
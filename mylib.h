#include <stdio.h>
#include <stdlib.h>

typedef struct mylist
{
	int data;
	struct mylist *next;
	struct mylist *prev;
} mylist;
mylist *Creat()
{
	mylist *new = (mylist *)malloc(sizeof(mylist));
	return new;
}
mylist *insert(mylist **head, int VALUE)
{
	struct mylist *new_node = (mylist *)malloc(sizeof(mylist));

	new_node->data = VALUE;
	new_node->next = *head;
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
}
mylist *FILL(struct mylist *head, int N)
{
	mylist *temp = head;
	while (temp != NULL)
	{
		temp->data = N;
		temp = temp->next;
	}
}
mylist *SEARCH(mylist *head, int VALUE)
{
	mylist *temp = head;
	while (temp != NULL)
	{
		if (temp->data == VALUE)
			return temp;
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

void REMOVE(mylist *head, int valuer)
{
	if (head->data == valuer)
	{
		printf("\ncannot do this for the moment \n");
		return;
	}
	else
	{
		mylist *temp = head;
		mylist *last = NULL;
		while (temp->data != valuer)
			temp = temp->next;
		if (temp != NULL)
		{
			last = temp->prev;
			last->next = temp->next;
			free(temp);
		}
	}
}

void printList(mylist *head)
{
	mylist *temp = head;
	if (head == NULL)
		printf("List is impty...\n");
	else
	{
		printf("\nthe element of the list :  \n");
		while (temp != NULL)
		{
			printf(" %d <->", temp->data);
			temp = temp->next;
		}
		printf(" NULL \n");
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct mylist
{
	int data;
	struct mylist *next;
	struct mylist *prev;
} mylist;
mylist *insert(mylist **head, int VALUE)
{
	struct mylist *new_node = (mylist *)malloc(sizeof(mylist));
	new_node->data = VALUE;
	new_node->next = *head;
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
  return (*head);
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
mylist *FILL_RANDOMLY(struct mylist  *head,int N){
    srand(time(NULL));
    while (N-- > 0)
    {
        int r = rand() % 100;
        head = insert(&head, r);
    }
    return head;
}
int Listsize(struct mylist  *head){
  mylist * current = head;
  int counter = 0;
  while (current){
    counter++;
    current = current->next;
  }
  return counter ;
}
void swap ( int* a, int* b )
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

 mylist *lastNode(mylist *last)
{
  while (last && last->next)
    last = last->next;
  return last;
}
mylist* select_random_pivot( mylist  *head){
    int x, N, i = 0;
    mylist *p = head;
    N= Listsize(head);
    srand(time(NULL));
    x = rand() % N;
    for (i = 0; i < x; i++)
    {
        p = p->next;
    }
    return p;
}
mylist* partition(struct mylist *first , struct mylist *last) //Pivot = last element
{
  mylist* pivot = select_random_pivot(first);
  struct mylist *i = first->prev; // i = NULL
  for (struct mylist *j = first; j != last; j = j->next)
  {
    if (j->data >= pivot->data)
    {//increment i
      if (i == NULL)
        i = first ;
      else
        i = i->next;
      swap(&(i->data), &(j->data));
    }
  }
  if (i == NULL)//increment i again
    i = first ;
  else
    i = i->next;
  swap(&(i->data), &(pivot->data));
  return i;
}

void recursive(struct mylist* first, struct mylist *last)
{
  if (last != NULL && first != last && first != last->next)
  {
    struct mylist *p = partition(first, last);
    recursive(first, p->prev);
    recursive(p->next, last);
  }
}

void quickSort(struct mylist  *head)
{
  mylist *last = lastNode(head);
  recursive(head, last);
}

int main()
{
    printf("\n\t\t\t\t\tQUICK Sort pevote radomly\n\n\n\n");
    mylist *head = NULL;
    int N;// list size
    printf("Enter the Lenght of the list : ");
    scanf("%d",&N);
    head = FILL_RANDOMLY(head,N);
    printf("before Sort : \n");
    printList(head);

    printf("\n\nAfter Sort : \n");
    clock_t t;
    t = clock();
    quickSort(head);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printList(head);
    printf("\nQUICKSORT took %f seconds to execute \n", time_taken);
    
    return 0;
}

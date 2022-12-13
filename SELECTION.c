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
void selectionSort(mylist *head)
{
    mylist *tmp = head;
    while (tmp)
    {
        mylist *max = tmp;
        mylist *r = tmp->next;
        while (r)
        {
            if (max->data < r->data)
                max = r; // Getting the max element
            r = r->next;
        }
        // Swapping the max with tmp
        if (max != tmp)
        {
            int x = tmp->data;
            tmp->data = max->data;
            max->data = x;
        }
        tmp = tmp->next;
    }
}
mylist *FILL_RANDOMLY(struct mylist *head, int N)
{
    srand(time(NULL));
    while (N-- > 0)
    {
        int r = rand() % 100;
        head = insert(&head, r);
    }
    return head;
}
void main()
{
    mylist *head = NULL;
    int N;
    printf("Enter the Number : ");
    scanf("%d",&N);
    head = FILL_RANDOMLY(head,N);
    printf("before Sort : \n");
    printList(head);

    printf("\n\nAfter Sort : \n");
    clock_t t;
    t = clock();
    selectionSort(head);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printList(head);
    printf("\nSELECTION SORT took %f seconds to execute \n", time_taken);
}

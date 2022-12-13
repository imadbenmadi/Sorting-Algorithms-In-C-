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
void insertionSort(mylist **head)
{
    mylist *sorted = NULL;
    mylist *current = *head;
    while (current)
    {
        mylist *next = current->next;
        current->prev = current->next = NULL;
        shiffting_Right(&sorted, current);
        current = next;
    }
    *head = sorted; // the new value of head is the first element of the sorted sublist
}
void shiffting_Right(mylist **head, mylist *newNode) // the head of the sorted sublist
{
    mylist *current;
    if (*head == NULL) // if the sorted sublist is empty
        *head = newNode;
    else if ((*head)->data <= newNode->data)
    { // insert before the head
        newNode->next = *head;
        newNode->next->prev = newNode;
        *head = newNode;
    }
    else
    {
        current = *head;
        while (current->next != NULL && current->next->data > newNode->data)
            current = current->next;
        newNode->next = current->next;
        if (current->next != NULL) // if the new node is not inserted at the end of the sorted sublist
            newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
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
    head = FILL_RANDOMLY(head, N);
    printf("before Sort : \n");
    printList(head);

    printf("\n\nAfter Sort : \n");
    clock_t t;
    t = clock();
    insertionSort(&head);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printList(head);
    printf("\nINSERTION SORT took %f seconds to execute \n", time_taken);
}

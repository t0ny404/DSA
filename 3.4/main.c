#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} NodeT;

NodeT* createNode(int key)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    if(p)
    {
        p->key = key;
        p->next = NULL;
    }
    return p;
}

typedef struct
{
    int length;
    NodeT *first, *current;
} CircularSLLT;

CircularSLLT *createEmptySLL()
{
   CircularSLLT*listPtr = (CircularSLLT*)malloc(sizeof(CircularSLLT));
    if(listPtr)
    {
        listPtr->length = 0;
        listPtr->first = listPtr->current = NULL;
    }
    return listPtr;
}

void del(CircularSLLT **head, int key)
{
    NodeT* temp = (*head)->first, *prev;

    if(temp != NULL && temp->key == key)
    {
        (*head)->first = temp->next;
        free(temp);
        (*head)->length--;
        return;
    }
    while(temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    (*head)->length--;
    prev->next = temp->next;

    (*head)->current = temp->next;
    free(temp);
}

void dcr(CircularSLLT** head)
{
    (*head)->current = (*head)->current->next;
    (*head)->length--;
}

void icr(CircularSLLT** head, int key)
{

    NodeT* temp = createNode(key);
    NodeT *last = (*head)->first;

    if (!last)
    {
       (*head)->first = temp;
       (*head)->current = temp;
       (*head)->length++;
       return;
    }


    while (last->next && last->next != (*head)->current)
        last = last->next;

    temp->next = (*head)->current;
    last->next = temp;
    (*head)->current = temp;
    (*head)->length++;
    return;
}


void ist(CircularSLLT** head, int key)
{
    NodeT* temp = createNode(key);
    temp->next = (*head)->first;
    (*head)->first = temp;
    (*head)->length++;
    (*head)->current = (*head)->first;
}

void dst(CircularSLLT** head)
{
    (*head)->first = (*head)->current = (*head)->first->next;
    (*head)->length--;
}

void prt(CircularSLLT* head)
{
    CircularSLLT* temp = createEmptySLL();
    *temp = *head;
    while(temp->first)
    {
        printf("%d ", temp->first->key);
        temp->first = temp->first->next;
    }

}

int main()
{
    CircularSLLT* head = createEmptySLL();
    ist(&head, 1);
    ist(&head, 2);
    ist(&head, 3);
    ist(&head, 4);
    del(&head, 3);

    prt(head);

    icr(&head, 5);
    icr(&head, 6);
    icr(&head, 7);
    icr(&head, 8);
    prt(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

Node* XOR (Node *a, Node *b)
{
    return (Node*)((int)(a) ^ (int)(b));
}

List* CreateEmpty () {

    List* listptr = (List*)malloc(sizeof(List));

    if(listptr)
    {
        listptr->first = listptr->last = NULL;
    }
    return listptr;
}

Node* CreateNode (List* listptr, int data) {

    Node* p = (Node*)malloc(sizeof(Node));
    if (p)
    {
        p->data = data;
        p->NxorP = XOR(NULL, listptr->first);
    }
    return p;
}

void insertAt(List* listptr, int data)
{
    Node *newnode = CreateNode(listptr, data);

    if (listptr->first)
    {
        Node* next = XOR(listptr->first->NxorP, NULL);
        listptr->first->NxorP = XOR(newnode, next);
    }
    else listptr->last = newnode;
    listptr->first = newnode;
}

void afis (FILE* fout, List* listptr, int direction)
{
    Node *current = direction;
    Node *prev = NULL;
    Node *next;


    if (direction == listptr->last)
    fprintf (fout, "Opposite direction: \n");
    if (direction == listptr->first)
    fprintf (fout, "Normal direction: \n");

    while (current)
    {
        fprintf (fout, "%d ", current->data);
        next = XOR (prev, current->NxorP);
        prev = current;
        current = next;
    }
}

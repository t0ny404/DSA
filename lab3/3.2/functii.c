#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

List* CreateEmpty () {

    List* listptr = (List*)malloc(sizeof(List));
    if (listptr)
    {
        listptr->count = 0;
        listptr->first = listptr->last = NULL;
    }
    return listptr;
}

Node* CreateNode ( char w[255] ) {

    Node* p = (Node*)malloc(sizeof(Node));
    if (p)
    {
        strcpy(p->word, w);
        p->apariti = 1;
        p->next = p->prev = NULL;
    }
    return p;
}

void insertInOrder ( List *listptr, char w[255] ) {

    Node* Next = listptr->first;
    Node* Prev = NULL;
    Node* p = CreateNode(w);

    while ( Next && (stricmp( Next->word, w ) < 0))
    {
        if (stricmp( Next->word, w) == 0)
        {
            Prev = Next;
            Next = Next->next;
        }
        Prev = Next;
        Next = Next->next;
    }

    if ( Next && strcmp(Next->word, w) == 0)
        Next->apariti++;
    else
    {
        if ( !listptr || listptr->count == 0 )
            listptr->first = listptr->last = p;

        else
        {
            if(Prev == NULL)
            {
                p->next = listptr->first;
                listptr->first->prev = p;
                listptr->first = p;
            }
            else if (Next)
            {
                p->next = Next;
                p->prev = Prev;
                Prev->next = p;
                Next->prev = p;
            }
            else
            {
                p->next = Next;
                p->prev = Prev;
                Prev->next = p;
                listptr->last = p;
            }
        }
            listptr->count++;
    }
}

void ascending(List *First, FILE *fout)
{
    Node *p = First->first;
    while(p != NULL)
    {
        fprintf(fout, "%s: %d \n", p->word, p->apariti);
        p = p->next;
    }
}

void descending(List *First, FILE *fout)
{
    Node *p = First->last;
    while(p != NULL)
    {
        if ( stricmp (p->word, p->prev) == 0 )
            fprintf(fout, "%s: %d \n", p->prev, p->prev->apariti);
        if ( stricmp (p->word, p->next) != 0 )
            fprintf(fout, "%s: %d \n", p->word, p->apariti);
        p = p->prev;
    }
}

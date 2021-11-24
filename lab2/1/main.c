#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int key;
    struct node *next;

} NodeT;

typedef struct
{
    int countt;
    NodeT *first;
    NodeT *last;

} List;

FILE* fin;
FILE* fout;

List *createEmptySLL()
{
    List*listPtr = (List*)malloc(sizeof(List));
    if(listPtr)
    {
        listPtr->countt = 0;
        listPtr->first = listPtr->last = NULL;
    }
    return listPtr;
}

int decimal(char *c)
{
    int d = 0;
    while (isdigit(*c))
    {
        d = d*10 + ((*c) - '0');
        c++;
    }
    return d;
}

List *garage;
List *road;

NodeT* createSLLNode (int truck_id)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    if(p)
    {
        p->key = truck_id;
        p->next = NULL;
    }
    return p;
}


int insertAtFront (List* listPtr, NodeT* p)
{
    if (listPtr)
    {
        p->next = listPtr->first;
        if (!listPtr)
        {
            listPtr->last = p;
        }
        listPtr->first = p;
        listPtr->countt++;
        return 1;
    }
    return 0;
}


int insertAtRear (List *listPtr, NodeT *p)
{
    if (listPtr)
    {
        if(!listPtr->first)
        {
            listPtr->first = p;
        }
        else
        {
            listPtr->last->next = p;
        }
        listPtr->last = p;
        listPtr->countt++;
        return 1;
    }
    return 0;
}


void addToRoad (int truck_id)
{
    NodeT* p = createSLLNode(truck_id);
    if(insertAtRear(road, p) == 0)
        fprintf(fout, "error");
}

NodeT* deleteFirst(List* listPtr)
{
    NodeT *p;
    if( listPtr->first != NULL)
    {
        p = listPtr->first;
        listPtr->first = listPtr->first->next;
        free(p);
        listPtr->countt--;
        if( listPtr->first == NULL)
            listPtr->last = NULL;
        return p;
    }
    return NULL;
}

int deleteByKey(List*listPtr, int truck_id)
{
    NodeT *q, *q1;
    q1 = NULL;
    q = listPtr->first;
    while (q != NULL)
    {
        if (q->key == truck_id)
            break;
        q1 = q;
        q = q->next;
    }
    if(q != NULL)
    {
        if(q == listPtr->first)
        {
            listPtr->first = listPtr->first->next;
            free(q );
            if (listPtr->first == NULL)
                listPtr->last = NULL;
        }
        else
        {
            q1->next = q->next;
            if(q == listPtr->last)
                listPtr->last = q1;
            free(q );
        }
        return 1;
    }
    return 0;
}


int enterGarage (int truck_id)
{
    NodeT* p = createSLLNode(truck_id);
    if (deleteByKey(road, truck_id) == 0)
    {
        fprintf(fout, "error: %d not on road!\n", truck_id);
        return -1;
    }
    return insertAtFront(garage, p);
}

int exitGarage(int truck_id)
{
    NodeT* p = createSLLNode(truck_id);
    if ( !garage->first || garage->first->key != p->key )
    {

        fprintf(fout, "error: %d not at exit!\n", truck_id);
        return -1;
    }
    deleteFirst(garage);
    return insertAtRear(road, p);
}

void afis(List* First)
{
    NodeT* p = First->first;
    if(First->first == NULL)
    {
        fprintf(fout, "none");
    }
    while(p != NULL)
    {
        fprintf(fout, "%d ", p->key);
        p = p->next;
    }
    fprintf(fout, "\n");
}

char buff[2000];

int main(int argc, char* argv[])
{
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    if (!fin) perror(argv[1]);
    if (!fout) perror(argv[2]);

    garage = createEmptySLL();
    road = createEmptySLL();

    while (fgets(buff, 1000, fin))
    {
        int ln = 0;
        while (buff[ln] != '\0')
            ln++;

        if (buff[ln-1] == '\n')
            buff[ln-1] = '\0';

        if (buff[1] != '(' || buff[strlen(buff)-1] != ')')
        {
            fprintf(fout, "error: not a command!\n");
        }
        switch(buff[0])
        {
        case 'R':
        {
            addToRoad(decimal(buff+2));
            break;
        }
        case 'E':
        {
            if (enterGarage(decimal(buff+2)) == 0)
                fprintf(fout, "error");
            break;
        }
        case 'X':
        {
            if (exitGarage(decimal(buff+2)) == 0)
                fprintf(fout, "error");
            break;
        }
        case 'S':
        {
            if (buff[2] == 'R')
            {
                fprintf(fout, "R: ");
                afis(road);
            }
            if (buff[2] == 'G')
            {
                fprintf(fout, "G: ");
                afis(garage);
            }
            break;
        }

        default:
            fprintf(fout, "error: not a command!\n");
            break;
        }
    }
    return 0;
}

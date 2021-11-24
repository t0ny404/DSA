#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

    char plecare[255];
    char destinatie[255];
    char car[2];
    int index;
    struct node* next;
    struct node* prev;

} Node;

typedef struct list {

    int count;
    Node* first;
    Node* last;

} List;


List* CreateEmpty () {

    List* listptr = (List*)malloc(sizeof(List));
    if (listptr)
    {
        listptr->count = 0;
        listptr->first = listptr->last = NULL;
    }
    return listptr;
}

Node* CreateNode ( char pl[255], char d[255] ) {

    Node* p = (Node*)malloc(sizeof(Node));
    if (p)
    {
        strcpy(p->plecare, pl);
        if(d)
        strcpy(p->destinatie, d);
        p->next = p->prev = NULL;
    }
    return p;
}

void insertInOrder ( List *listptr, char pl[255], char d[255] ) {

    Node* Next = listptr->first;
    Node* Prev = NULL;
    Node* p = CreateNode( pl, d );

    while ( Next && ( (stricmp( Next->plecare, pl ) < 0) || ( stricmp( Next->plecare, pl) == 0 && stricmp( Next->destinatie, d ) < 0 ))  )
    {
        Prev = Next;
        Next = Next->next;
    }

    if ( !( Next && ( (stricmp( Next->plecare, pl ) < 0) || ( stricmp( Next->plecare, pl) == 0 && stricmp( Next->destinatie, d ) < 0 )) ) )
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

void ascending(List *First, FILE* out )
{
    Node *p = First->first;
    while(p != NULL)
    {
        fprintf( out, "%s %s %s-%d \n", p->plecare, p->destinatie, p->car, p->index );
        p = p->next;
    }
}

int main()
{
    FILE* in = fopen( "input.txt", "r" );
    FILE* out = fopen( "output.txt", "w");
    if( !in ) perror( "input.txt" );

    int used = 0, usedA1 = 0;
    char previous[255] = "";

    List* curse = CreateEmpty();
    List* onorate = CreateEmpty();

    int nr;
    fscanf( in, "%d", &nr );
    for( int i = 0; i < nr; i++ )
    {
        char plecare[255], destinatie[255];
        fscanf( in, "%s %s", plecare, destinatie );
        insertInOrder( curse, plecare, destinatie );
    }

    char destinatiiO[255], buf[2];
    fscanf( in, "%s", destinatiiO );
    insertInOrder( onorate, destinatiiO, NULL );
    fgets( buf, 2, in );
    while( buf[0] == ' ' )
    {
        fscanf( in, "%s", destinatiiO);
        insertInOrder( onorate, destinatiiO, NULL );
        fgets( buf, 2, in );
    }


    Node* o = onorate->first;
    for( int i = 0; i < onorate->count; i++ )
    {
        Node* p = curse->first;

        while( p )
        {
        if( stricmp( p->plecare, o->plecare ) == 0 || stricmp( p->destinatie, o->plecare ) == 0 )
        {
            strcpy( p->car, "A2" );
            if( stricmp( p->car, previous ) == 0 )
            p->index = used++;
            else p->index = used;
            strcpy( previous, p->car );
        }
        p = p->next;
        }
        o = o->next;
    }

    Node* p = curse->first;
    for( int i = 0; i < curse->count; i++ )
    {
        if( p->car[0] != 'A' )
            {
                strcpy( p->car, "A1" );
                p->index = usedA1++;
            }
            p = p->next;
    }

ascending( curse, out );
    return 0;
}

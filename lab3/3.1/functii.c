#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

List* CreateList (int size) {

    List* listptr = (List*)malloc (sizeof(List));

    if (listptr)
    {
        listptr->data = (Node*)calloc(size+1, sizeof(Node));
        if (listptr->data)
        {
            listptr->capacity = size;

            for ( int i = 1; i <= size; i++)
            {
                listptr->data[i].count = listptr->data[i].key = i;
                listptr->data[i].next = i+1;

            }
             listptr->data[size].next = 1;

        } else {
            free(listptr);
            listptr = NULL;}
   }
      return listptr;
    }

int keepLoop (int j, int size) {

    if ( j > size )
        return keepLoop(j - size, size);
    else
        return j;

}

int delet (List* listptr, int gkey){

    int current = -1, j;

    for ( int i = 1; i <= listptr->capacity; i++)
        if(listptr->data[i].key == gkey)
        {

            current = listptr->data[keepLoop(i+1, listptr->capacity)].key;
            j = i;

            while ( j <= listptr->capacity )
            {
                listptr->data[j].key = listptr->data[keepLoop(j+1, listptr->capacity)].key;
                listptr->data[j].next = listptr->data[keepLoop(j+1, listptr->capacity)].next;
                j++;
            }
                (listptr->capacity)--;
                break;
        }

    return current;
    }

int winner ( List* listptr, int n ) {

int i = 1, t, j, current = -1;

while ( listptr->capacity > 1)
{
    if ( listptr->data[i].count == n)
       current = delet(listptr, listptr->data[i].key);

    if( listptr->data[i].key == current)
    {
        listptr->data[i].count = 1;
        t = 1;
        j = i+1;
        while ( t <= n)
        {
            j = keepLoop(j, listptr->capacity);
            listptr->data[j].count = ++t;
            j++;
        }
    }
    i++;
    i = keepLoop(i, listptr->capacity);
    }
    if ( current == -1 )
    {
        printf("error");
        return -1;       }
    return listptr->data[1].key;
}


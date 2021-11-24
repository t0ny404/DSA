#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int f( char* key )
{
    int sum = 0;
    for( int i = 0; i< strlen( key ); i++ )
        sum += key[i];
    return( sum % B );
}

char* readname( FILE* in )
{
    char ch[2];
    char* name = (char*)malloc( sizeof( char ) * 100);
    name[0] = '\0';

    fgets( ch, 2, in );
    while( ch[0] != '\n' )
    {
        strcat( name, ch );
        fgets( ch, 2, in );
    }
    return name;
}

void insertc( Node* table[B], char* key, FILE* out )
{
    Node* p = (Node*)malloc( sizeof( Node ) );
    if( p )
    {
        strcpy( p->key, key );
        p->next = NULL;
    }
    else fprintf( out, "ERROR in inserting %s\n", key );

    int h = f( key );
    p->next = table[h];
    table[h] = p;
}

void afis( Node* table[B], FILE* out )
{
    Node* p;
    for( int i = 0; i < B; i++ )
        if( table[i] != NULL )
        {
            fprintf( out, "%d: ", i );
            p = table[i];
            while( p )
            {
                fprintf( out, "%s", p->key );
                if( p->next )
                    fprintf( out, ", " );
                p = p->next;
            }
            fprintf( out, "\n" );
        }

}

void find( Node* table[B], char* key, FILE* out )
{
    int h = f( key );
    Node* p = (Node*)malloc( sizeof(Node) );
    p = table[h];
    while( p )
    {
        if( strcmp( key, p->key ) == 0 )
            {
                fprintf( out, "yes %d\n", h );
                return;
            }
        p = p->next;
    }
    fprintf( out, "no\n" );
}

void delet( Node* table[B], char *key, FILE* out )
{
    int h = f( key );
    int deleted = 0;
    Node* p = table[h];
    Node* temp = NULL;

    if( strcmp( p->key, key ) == 0)
    {
        table[h] = p->next;
        free(p);
    }
    else
    {
        while( p && !deleted )
        {
            if( strcmp( p->key, key ) == 0)
            {
                temp->next = p->next;
                free(p);
                deleted = 1;
            }
            temp = p;
            p = p->next;
        }
        if( !deleted) fprintf( out, "%s can not be deleted\n", key );
    }
}

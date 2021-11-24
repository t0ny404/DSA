#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int f1( char* key )
{
    int sum = 0;
    for( int i = 0; i< strlen( key ); i++ )
            sum += key[i];
    return( sum % B );
}
int f( char* key, int i )
{
    return ( f1( key ) + i + i*i ) % B;
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

void insertq( Node* table[B], char* key, FILE* out, int trial )
{
    int h = f( key, trial );

    if ( trial <= B )
        if ( !table[h] )
        {
            table[h] = (Node*)malloc( sizeof( Node ) );
            if( !table[h] )
                fprintf( out, "ERROR in inserting %s\n", key );
            strcpy( table[h]->key, key );
        }
        else
            insertq( table, key, out, trial + 1 );
    else
        fprintf( out, "ERROR in inserting %s\n", key );
}

void afis( Node* table[B], FILE* out )
{
    for( int i = 0; i < B; i++ )
        if( table[i] != NULL )
            fprintf( out, "%d: %s\n", i, table[i]->key );
}

int find( Node* table[B], char* key, int trial )
{
    int h = f( key, trial );
    if( trial <= B )
        if( table[h] && strcmp( key, table[h]->key ) == 0  )
            return h;
        else
            return find( table, key, trial + 1 );
    else
            return -1;
}

void delet( Node* table[B], char *key, FILE* out )
{
    int h = find( table, key, 0 );

    if( h != -1 && strcmp( table[h]->key, key ) == 0  )
        table[h] = NULL;

    else fprintf( out, "%s can not be deleted\n", key );
}

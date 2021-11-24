#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int main( int argv, char* argc[] )
{

    FILE* in = fopen( argc[1], "r" );
    FILE* out = fopen( argc[2], "w" );

    if( !in ) perror( argc[1] );
    if( !out ) perror( argc[2] );


    Node* table[B];
    for( int i = 0; i < B; i++ )
        table[i] = NULL;

    char buff;

    while( fscanf( in, "%c", &buff ) != -1 )
        switch( buff )
        {
        case 'i':
        {
            insertc( table, readname( in ), out );
            break;
        }
        case 'd':
        {
            delet( table, readname( in ), out );
            break;
        }
        case 'f':
        {
            find( table, readname( in ), out );
            break;
        }
        case 'l':
        {
            afis( table, out );
            break;
        }
        }

    fclose( in );
    fclose( out );
    return 0;
}

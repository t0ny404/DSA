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
            insertq( table, readname( in ), out, 0 );
            break;
        }
        case 'd':
        {
            delet( table, readname( in ), out );
            break;
        }
        case 'f':
        {
            int h = find( table, readname( in ), 0 );
            if( h != -1 )
                fprintf( out, "yes %d\n", h );
            else
                fprintf( out, "no\n" );

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

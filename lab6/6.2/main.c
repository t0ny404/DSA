#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

/* For the hash function in the first trial I choose polynomial accumulation because it is especially suitable for strings
(for x = 33 we have at most 6 collisions on a set of 50,000 English words). If, in the first trial in inserting a student's name,
there was a collision, I used quadratic probing (h(k,i)=(h'(k)+c1*i+c2*i*i), with c1=c2=1), which operates by taking the original hash index
and adding successive values of a quadratic polynomial until an open slot is found. It can be a more efficient algorithm in a open addressing
table, since it better avoids the clustering problem that can occur with linear probing.
*/

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

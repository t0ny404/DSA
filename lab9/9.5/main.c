#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int n;                                              //nr of elements
    fscanf( in, "%d ", &n );

    int A[n];
    readArray( A, n, in );                              //the sorted array

    int elem;
    fscanf( in, "%d ", &elem );                         //the searched element

    fprintf( out, "%d", BinaryS( A, 0, n-1, elem ) );   //the number indicating the position of the searched element

    fclose( in );
    fclose( out );
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int n;                                              //nr of elements in sequence
    fscanf( in, "%d ", &n );

    int A[n];
    readArray( A, n, in );                              //the unimodal sequence

    fprintf( out, "%d", Top( A, 0, n-1 ) );             //top of the unimodal sequence

    fclose( in );
    fclose( out );
    return 0;
}


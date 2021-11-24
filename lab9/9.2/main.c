#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int n;                                              //nr of days
    fscanf( in, "%d ", &n );

    double P[n];
    readArray( P, n, in );                              //the stock prices

    fprintf( out, "%lf", MaxProfit( P, 0, n-1 ) );       //value of maximum profit

    fclose( in );
    fclose( out );

    return 0;
}

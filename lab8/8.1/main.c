#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int n, W;
    fscanf( in, "%d %d", &n, &W );

    ItemT  itm[n];                                            //structure to hold the value, weight, density for every item
    init( n, itm, in );                                      //for reading the n items (weight and value for every item)

    afisGreedy( n, W, itm, zero_one, out );                  //print the result for the 0-1 problem
    fprintf( out, "\n" );
    afisGreedy( n, W, itm, Fractional, out );                //print the result for the fractional problem

    fclose( in );
    fclose( out );

    return 0;
}

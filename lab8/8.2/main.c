#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int n;
    fscanf( in, "%d", &n );

    ActivityT A[n];                              //structure to hold the activity, its start and finish time
    init( n, A, in );                           //for reading the n activities (and start and finish for every activity)

    Greedy( n, A );                             //setting the maximal set of mutually compatible activities

    printActivities( n, A, out );               //printing the list of scheduled activities in the order they took place

    fclose( in );
    fclose( out );
    return 0;
}

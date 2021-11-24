#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

#define source 1   // the starting vertex

int main( int argv, char* argc[] )
{
    FILE* in = fopen( argc[1], "r" );
    FILE* out = fopen( argc[2], "w" );

    if( !in ) perror( argc[1] );
    if( !out ) perror( argc[2] );

    int cost[Nmax][Nmax];
    init( cost );      // initialize the cost matrix with the cost if (i, j) belongs to E, with 0 if i=j and with infinity otherwise
    int V = read( cost, in ); //=|V|

    Dijkstra( V, cost, source, out );  //apply Dijkstra and print

return 0;
}

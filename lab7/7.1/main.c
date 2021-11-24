#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argv, char* argc[] )
{
    FILE* in = fopen( argc[1], "r" );
    FILE* out = fopen( argc[2], "w" );

    if( !in ) perror( argc[1] );
    if( !out ) perror( argc[2] );

    int V = ReadNodes( in );  //the nr of nodes
    int G[V+1][V+1];
    initG( V, G );   // initialize the adjacency matrix with 0

    ReadArcs( V, G, in );  //build the adjacency matrix of the directed graph

    int v[V];        //the elements of V', |V'|<|V|
    int V2 = ReadNodes2( V, v, in ); // =|V'|

    PrintArcs( V, G, V2, v, out );

    return 0;
}

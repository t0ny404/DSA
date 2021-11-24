#include <stdio.h>
#include <stdlib.h>
#include "functii.h"
#include "BfsDfs.h"

#define source 4        //the starting vertex

int main( int argv, char* argc[] )
{
    FILE* in = fopen( argc[1], "r" );
    FILE* out = fopen( argc[2], "w" );

    if( !in ) perror( argc[1] );
    if( !out ) perror( argc[2] );

    int V = ReadNodes( in );  //nr of nodes
    int G[V+1][V+1];
    initG( V, G );     //initialize with 0 the adjacency matrix

    ReadArcs( V, G, in );  //build the adjacency matrix for undirected graph

    bfs( V, G, source, out );
    fprintf( out, "\n" );       //print the traversals of bfs and dfs algorithms
    dfs( V, G, source, out );

    return 0;
}

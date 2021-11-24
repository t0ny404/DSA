#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int StrToInt ( char node[5] )
{
    int nr = 0, i = 0;
    while( node[i] != '\0' )
        nr = nr * 10 + ( node[i++] - '0' );

    return nr;
}

int ReadNodes( FILE* in )
{
    char buffer[8], node[5];

    fgets( buffer, 8, in );
    buffer[0] = '\0';
    fgets( buffer, 2, in );

    while( buffer[0] != '\n' )
    {
        node[0] = '\0';
        while( buffer[0] != ' ' && buffer[0] != '\n' )
        {
            strcat( node, buffer );
            fgets( buffer, 2, in );
        }
        if( buffer[0] != '\n' )
            fgets( buffer, 2, in );  // next node
    }
    return StrToInt( node );  // return the last node which is the biggest node and represents the size of the matrix
}

void initG( int V, int G[V+1][V+1] )
{
    for( int i = 1; i <= V; i++ )
        for( int j = 1; j <= V; j++ )
            G[i][j] = 0;
}

void ReadArcs( int V, int G[V+1][V+1], FILE* in )
{
    char buffer[8], arcs[12];
    int v, w;

    fgets( buffer, 7, in );
    buffer[0] = '\0';
    fgets( buffer, 2, in );

    while( buffer[0] != '\n' )
    {
        arcs[0] = '\0';
        while( buffer[0] != ')' && buffer[0] != '\n' )
        {
            strcat( arcs, buffer );
            fgets( buffer, 2, in );
        }
        if( buffer[0] != '\n' )
            fgets( buffer, 2, in );   //next pair

        sscanf( arcs, " (%d %d", &v, &w );
        G[v][w] = 1; G[w][v] = 1;        //undirected graph
    }
}

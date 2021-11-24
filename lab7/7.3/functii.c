#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int read( int cost[Nmax][Nmax], FILE* in )
{
    int v, w, c, max = 0;
    char buffer[50];
    while( fscanf( in, "%s", buffer ) != EOF )
    {
        sscanf( buffer, "%d,%d=%d", &v, &w, &c ); //(i, j) from E and the cost
        cost[v][w] = c;
        if( v > max )
            max = v;
        if( w > max )
            max = w;
    }
    return max;  //|V|
}

void init( int cost[Nmax][Nmax] )
{
    for( int i = 1; i < Nmax; i++ )
        for( int j = 1; j < Nmax; j++ )
        if( i == j )
        cost[i][j] = 0;
        else cost[i][j] = INF;
}

int min( int V, int dist[], int S[] )
{
    int min = INT_MAX, minIndex;

    for ( int v = 1; v <= V; v++ )
        if ( S[v] == 0 && dist[v] <= min )
            {
                min = dist[v];
                minIndex = v;
            }
    return minIndex;   // return the unselected node with dist from source minimal
}

void Dijkstra( int V, int cost[Nmax][Nmax], int src, FILE* out )
{
    int S[V], dist[V], traversal[V];

    for ( int i = 1; i <= V; i++ )
    {
        S[i] = 0;     // set S empty
        dist[i] = cost[src][i];
    }
    S[src] = 1;   // add source to set S
    dist[src] = 0;
    traversal[0] = src;

    for ( int step = 1; step <= V-1; step++ )
    {
        int k = min( V, dist, S );
        S[k] = 1; // add k to set S
        for ( int j = 1; j <= V; j++ )
            if ( S[j] == 0 && ( dist[k] + cost[k][j] < dist[j] ) )
                dist[j] = dist[k] + cost[k][j];

        traversal[step] = k;
    }
   print( V, dist, traversal, out );
}

void print( int V, int dist[V], int traversal[V], FILE* out )
{
    int sum = 0;
    for( int i = 1; i < V; i++ )
        if( dist[traversal[i]] < INF )
            sum = sum + dist[traversal[i]];
        else
        {
            fprintf( out, "Impossible" );  // if one of the vertices is not reachable from the source in the directed graph
            return;
        }
    fprintf( out, "%d ", sum );   // the minimum cost

    for( int i = 0; i < V-1; i++ )
        fprintf( out, "%d-", traversal[i] );
    fprintf( out, "%d (", traversal[V-1] );  // the nodes

    for( int i = 1; i < V-1; i++ )
        fprintf( out, "%d,", dist[traversal[i]] );  // the distance of the shortest path from the source to every node
    fprintf( out, "%d)",  dist[traversal[V-1]] );
}

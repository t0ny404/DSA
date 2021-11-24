#include <stdio.h>
#include <stdlib.h>
#include "StackQueue.h"
#include "BfsDfs.h"

void bfs( int V, int G[V+1][V+1], int src, FILE* out )
{
    int mark[V]; // for marking visited nodes
    Queue* Q = createQueue(); // queue of nodes

    for ( int i = 1; i <= V; i++ ) // mark all nodes unvisited
        mark[i] = UNVISITED;
    mark[src] = VISITED; // mark source node visited

    fprintf( out, "BFS: %d ", src );
    enqueue( Q, src ); // src will be the first node dequeued in the loop below

    while( !isEmptyQ( Q ) )
    {
        int v = dequeue( Q );

        for ( int w = 1; w <= V; w++ )
            if( G[v][w] == 1 )            //for each node adjacent to v
                if ( mark[w] == UNVISITED )
                {
                    mark[w] = VISITED;
                    fprintf( out, "%d ", w );
                    enqueue( Q, w );
                }
    }
}

void dfs( int V, int G[V+1][V+1], int src, FILE* out )
{
    int mark[V]; // for marking visited nodes
    Stack* S = createStack(); // stack of nodes

    for (int i = 1; i <= V; i++) // mark source node visited
        mark[i] = UNVISITED;
    mark[src] = VISITED; // mark source node visited

    fprintf( out, "DFS: %d ", src );

    push( S, src );
    while ( !isEmptyS( S ) )
    {
        int v = top( S );
        int w = 1;
        while( ( G[v][w] != 1 || mark[w] == VISITED ) && w <= V )
            w++;                                        //let w be the next unvisited node adjacent to v
        if ( w <= V )
        {
            mark[w] = VISITED;
            fprintf( out, "%d ", w );
            push( S, w );
        }
        else
            pop( S );
    }
}

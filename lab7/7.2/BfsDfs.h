#ifndef BFSDFS_H_INCLUDED
#define BFSDFS_H_INCLUDED

enum { UNVISITED, VISITED };

void bfs( int V, int[V+1][V+1], int, FILE* );
void dfs( int V, int[V+1][V+1], int, FILE* );

#endif // BFSDFS_H_INCLUDED

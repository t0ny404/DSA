#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

int StrToInt( char[] );
int ReadNodes( FILE* );
void ReadArcs( int V, int[V+1][V+1], FILE* );
void initG( int V, int[V+1][V+1] );
int ReadNodes2( int V, int[V], FILE* );
void PrintArcs( int V, int[V+1][V+1], int V2, int[V], FILE* );

#endif // FUNCTII_H_INCLUDED

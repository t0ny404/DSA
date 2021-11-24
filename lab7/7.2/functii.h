#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

int StrToInt( char[] );
int ReadNodes( FILE* );
void ReadArcs( int V, int[V+1][V+1], FILE* );
void initG( int V, int[V+1][V+1] );

#endif // FUNCTII_H_INCLUDED

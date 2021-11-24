#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#define Nmax 100
#define INF 10000

int read( int[Nmax][Nmax], FILE* );
void init( int[Nmax][Nmax] );
void Dijkstra( int V, int[Nmax][Nmax], int, FILE* );

#endif // FUNCTII_H_INCLUDED

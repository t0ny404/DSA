#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#define INF ( INT_MAX / 2 )

typedef struct{

    int engineer;
    int conductor;

} WorkerT;

int opSalary( int N, WorkerT w[N+1] );
int opSalary2( int N, WorkerT w[N+1] );

#endif // FUNCTII_H_INCLUDED

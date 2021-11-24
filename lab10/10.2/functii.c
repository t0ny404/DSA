#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

 //find minimum of two integer values
int min( int x, int y )
{
    return ( x < y )? x : y;
}

//find the optimal cost of hiring j workers from crew 1 to i
int Salary( int i, int j, int N, WorkerT w[N+1] )
{
    if( i - j < j )                 //to verify the age constraint
        return INF;
    if( i <= 1 && j <= 0 )          //base case, as the first worker is the youngest it must be a conductor
        return w[1].conductor;

    return min( Salary( i - 1, j - 1, N, w ) + w[i].engineer,
               Salary( i - 1, j, N, w ) + w[i].conductor );
}

//find the optimal cost of hiring the workers
int opSalary( int N, WorkerT w[N+1] )
{
    return w[N].engineer + Salary( N - 1, ( N / 2 ) - 1, N, w );    //as the last worker is the oldest, it must be an engineer
}

int opSalary2( int N, WorkerT w[N+1] )
{
    int cost[N][( N / 2 )];

    for( int i = 0; i <= N - 1; i++ )
    {
        if( i <= ( ( N / 2 ) - 1 ) )
            cost[0][i] = INF;
        cost[i][0] = INF;
    }

    cost[1][0] = w[1].conductor;

    for( int j = 1; j <= ( N / 2 ) - 1; j++ )
        for( int i = j; i <= N - 1; i++ )
        {
            if( ( i + 1 - j ) < j || j < ( ( i  )/ 2 )  )
                cost[i][j] = INF;

            else cost[i][j] = min( ( cost[i-1][j-1] + w[i].engineer ), (cost[i-1][j] + w[i].conductor ));
        }

    return w[N].engineer + cost[N - 1][( N / 2 ) - 1];
}

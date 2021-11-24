#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void readArray( int A[], int n, FILE* in )
{
     for( int i = 0; i < n; i++ )
        fscanf( in, "%d ", &A[i] );
}

int max( int x, int y )                                 //find maximum of two integer values
{
    return ( x > y )? x : y;
}

int sumaMid( int A[], int p, int m, int q )           //find the sum of the subarray that crosses the middle
{
    int sum = 0, left = A[m], right = A[m+1];

    for ( int i = m; i >= p; i-- )
    {
        sum = sum + A[i];
        if( sum > left )                            //obtain the subarray starting from middle to the begging with the biggest sum
            left = sum;
    }
    sum = 0;                                        //reinitialize sum with 0

    for ( int i = m+1; i <= q; i++ )
    {
        sum = sum + A[i];
        if( sum > right )                           //obtain the subarray starting from middle to the end with the biggest sum
            right = sum;
    }
    return left + right;                            //combine the 2 subarrays
}

int DivAndCon ( int A[], int p, int q )
{
    if( p == q )
        return A[p];

    int m = ( p + q ) / 2;

    int sumL = DivAndCon( A, p, m), sumR = DivAndCon( A, m+1, q), sumM = sumaMid( A, p, m, q);   //split the problem into subproblems

    return max( max( sumL, sumR ), sumM );                                                       //combine the solution (choose subarray with biggest sum)
}

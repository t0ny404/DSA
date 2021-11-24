#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void readArray( int A[], int n, FILE* in )
{
     for( int i = 0; i < n; i++ )
        fscanf( in, "%d ", &A[i] );
}

int Top( int A[], int l, int r )                        //recursive function based on binary search => cost ~ O(log n)
{
    if( l >= r )
        return A[r];                                    //the unimodal sequence can be the form of a < b < c <... or a > b > c >..., thus the top is a

    int mid = ( l + r ) / 2;

    if( A[mid] > A[mid-1] && A[mid] > A[mid+1] )       //if the prev < middle > next then it is the top (prev>previous elems & next>following elems due to unimodal seq)
        return A[mid];

    if( A[mid] > A[mid-1] )
        return Top( A, mid+1, r );                     //if prev < mid < next then go to the right half
    else return Top( A, l, mid-1 );                    //if prev > mid > next then go to the left half
                                                       //can't have prev > mid < next due to the fact that the seq is unimodal
}

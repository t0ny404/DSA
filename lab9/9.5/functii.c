#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void readArray( int A[], int n, FILE* in )
{
     for( int i = 0; i < n; i++ )
        fscanf( in, "%d ", &A[i] );
}

int BinaryS( int A[], int l, int r, int elem )      //Binary Search
{
    if( l > r )
        return 0;

    int mid = ( l + r ) / 2;

    if( elem == A[mid] )
        return mid+1;

    if( elem > A[mid] )
        return BinaryS( A, mid+1, r, elem );
    else return BinaryS( A, l, mid-1, elem );
}

#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void init( int n, ActivityT A[n], FILE* in )               //for reading the n activities (start and finish time for every activity)
{
    for( int i = 0; i < n; i++ )
    {
        fscanf( in, "%d %d", &A[i].s, &A[i].f );
        A[i].compatible = false;                           //initializing the set of compatible events as empty
        A[i].name = i + 1;                                //the set of activities (unordered)
    }
}

int byFinish( const void* a, const void* b )             //sorting the activity array ascending by finish time
{
    if ( ((ActivityT *)a)->f < ((ActivityT *)b)->f ) return -1;
    return 1;
}

void Greedy( int n, ActivityT A[n] )
{
    qsort( A, n, sizeof(ActivityT), byFinish );          //sorting the array

    int prev = 0;                                       //schedule first activity that ends first
    A[0].compatible = true;

    for( int i = 1; i < n; i++ )
        if( A[i].s >= A[prev].f )                       //check if current activity's time span don't intersect with previous'
        {
            A[i].compatible = true;                     //add the activity to the set of compatible activities
            prev = i;                                   //schedule i next
        }
}

void printActivities( int n, ActivityT A[n], FILE* out )
{
    for( int i = 0; i < n; i++ )
        if( A[i].compatible == true )                   //print the activities from the set of compatible activities
        fprintf( out, "%d ", A[i].name );                //print them in the order they took place
}

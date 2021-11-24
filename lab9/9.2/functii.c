#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void readArray( double P[], int n, FILE* in )
{
     for( int i = 0; i < n; i++ )
        fscanf( in, "%lf ", &P[i] );
}

double max( double x, double y )                                 //find maximum of two integer values
{
    return ( x > y )? x : y;
}

double maxSeq( double P[], int l, int r )                       //find maximum of a sequence
{
    double max = P[l];
    while( l <= r )
    {
        if( P[l] > max )
            max = P[l];
        l++;
    }
    return max;
}

double minSeq( double P[], int l, int r )                       //find minimum of a sequence
{
    double min = P[l];
    while( l <= r)
    {
        if( P[l] < min )
            min = P[l];
        l++;
    }
    return min;
}

double MaxProfit( double P[], int l, int r )
{
    if( l == r )                                                           //base case
        return 0;

    int m = ( l + r ) / 2;

    double mL = MaxProfit( P, l, m ), mR = MaxProfit( P, m+1, r );          //buy and sell within the first half and then same but in the second half
    double vL = minSeq( P, l, m ), vR = maxSeq( P, m+1, r );                //buy before day 'm' and sell after day 'm'

    return max( max( mL, mR ), ( vR - vL ) );                               //maximum profit
}

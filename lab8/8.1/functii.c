#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void init( int n, ItemT itm[n], FILE* in )               // for reading the n items (weight and value for every item)
{
    for( int i = 0; i < n; i++ )
    {
        fscanf( in, "%f %f", &itm[i].w, &itm[i].v );
        itm[i].density = itm[i].v / itm[i].w;           //computing the density for every item
    }
}

int byValue( const void* a, const void* b )             //functions for the quick sort
{                                                       //sorting the item array descending by value, and if 2 values are equal, ascending by weight
    if ( ((ItemT *)a)->v < ((ItemT *)b)->v ) return 1;
    if ( ((ItemT *)a)->v == ((ItemT *)b)->v && ((ItemT *)a)->w > ((ItemT *)b)->w ) return 1;
    return -1;
}

int byDensity( const void* a, const void* b )          //sorting the item array descending by value density
{
    if ( ((ItemT *)a)->density < ((ItemT *)b)->density ) return 1;
    return -1;
}

int byWeight( const void* a, const void* b )           //sorting the item array ascending by weight, and if 2 weights are equal, descending by value
{
    if ( ((ItemT *)a)->w < ((ItemT *)b)->w ) return -1;
    if ( ((ItemT *)a)->w == ((ItemT *)b)->w && ((ItemT *)a)->v > ((ItemT *)b)->v ) return -1;
    return 1;
}

ItemT greedy( int n, int W, ItemT itm[n], int posib, int caz )
{
    ItemT total;                                             //total amount taken into the knapsack
    total.v = total.w = 0;

    switch( posib )                                         //choosing one of the three possibilities (Greedy by profit, by weight, by profit density)
    {                                                       //rearranging the set of candidate elements depending on the selected possibility
        case Value:
         qsort( itm, n, sizeof(ItemT), byValue );
        break;

        case Weight:
         qsort( itm, n, sizeof(ItemT), byWeight );
        break;

        case Density:
         qsort( itm, n, sizeof(ItemT), byDensity );
        break;
    }

    for ( int i = 0; i < n; i++ )                           //for every element of the candidate set, we check if it's a solution
        if( total.w + itm[i].w <= W )                       //eg. by adding it's weight to the total weight we have so far and not exceeding W(the knapsack max capacity)
        {
            total.w += itm[i].w;
            total.v += itm[i].v;                            //if the item is a solution we add it to the sum of solution elements(the sum of values)
        }
        else                                                //if we are in the fractional pb, we reach the max capacity of the knapsack
            if( caz == Fractional )                         //by taking a fraction of the item weight until the knapsack is full,
            {                                               //and a fraction of the value, which is directly proportional
                total.v = total.v + ( W - total.w ) * itm[i].density;
                total.w = W;
            }
    return total;
}

void afisGreedy( int n, int W, ItemT itm[n], int caz, FILE* out )
{
    ItemT total[3];                                                          //print the best solution from all three Greedy possibilities
    total[0] = greedy( n, W, itm, Value, caz );
    total[1] = greedy( n, W, itm, Weight, caz );
    total[2] = greedy( n, W, itm, Density, caz );

    qsort( total, 3, sizeof(ItemT), byValue );                               //(one with the biggest total value)
    fprintf( out, "%.2f %.2f", total[0].w, total[0].v );
}

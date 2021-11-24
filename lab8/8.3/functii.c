#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void init( int n, WorkerT man[n], FILE* in )               //for reading the n workers
{
    for( int i = 0; i < n; i++ )
    {
        fscanf( in, "%d %d %d", &man[i].T, &man[i].X, &man[i].Y );
        man[i].paid = false;                               //initialize the worker as unpaid
        man[i].productivity = (float) man[i].Y / man[i].X;
    }
}

int maxIndex( WorkerT man[], int schimbari, int available[schimbari], int maxT )
{
    static int i = 0, max = 0, index = 0;              //at every new time, the new available workers (their speed) are compared with the old ones (which stay the same)

    while( i < schimbari )
        {
            if( man[available[i]].T > maxT )           //if the current time did not reach next available (worker) time then stop
                break;
            if( man[available[i]].Y > max )           //find the available worker (till the current time) with the biggest speed
            {
                max = man[available[i]].Y;
                index = available[i];
            }
            i++;
        }
    return index;                                   //return it
}

int byTime( const void* a, const void* b )           //sorting the workers array ascending by their available time,
{                                                    //and if 2 have the same time, descending by productivity, then by speed
    if ( ((WorkerT *)a)->T < ((WorkerT *)b)->T ) return -1;
    if ( ((WorkerT *)a)->T == ((WorkerT *)b)->T )
    {
        if( ((WorkerT *)a)->productivity > ((WorkerT *)b)->productivity ) return -1;
        if( ((WorkerT *)a)->productivity == ((WorkerT *)b)->productivity && ((WorkerT *)a)->Y > ((WorkerT *)b)->Y ) return -1;
    }
    return 1;
}

int Repaint( int n, int D, WorkerT man[n] )
{
    qsort( man, n, sizeof( WorkerT ), byTime );                //sorting the workers by their available time

    int available[n], schimbari = 1;                           //an array holding the positions where available time changes in the workers sorted array
    int i, total = 0, current = man[0].T;                      //set current time (start time) to available time of the first available worker; total cost to 0

    for( i = 0; i < n; i++ )
        if( i > 0 && man[i].T != man[i-1].T )
            available[schimbari++] = i;                       //available array also hold the position in workers array with biggest speed
    available[0] = 0;

    while( D > 0 )                                             //while the house is not fully painted
    {
        i = maxIndex( man, schimbari, available, current );    //get index of the worker with the biggest speed available through current time

        if( man[i].paid == false )                             //pay him if he was not paid, but only pay once
        {
            total += man[i].X;
            man[i].paid = true;
        }
        D -= man[i].Y;                                         //paint the house
        current++;                                             //advance 1 unit of time
    }

    return total;
}

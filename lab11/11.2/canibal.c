#include <stdio.h>
#include <stdlib.h>
#include "canibal.h"

/// Priority Queue ///

//remove the node with the highest priority from the queue
StateT* top( StateNodeT** head )
{
    return (*head)->state;
}
void pop( StateNodeT** head )
{
    StateNodeT* temp = *head;
    (*head) = (*head)->next;
    free( temp );
}

//push to queue according to priority
void push( StateNodeT** head, StateT* nw, int numP )
{
    StateNodeT* start = (*head);
    StateNodeT* temp = (StateNodeT*)malloc( sizeof( StateNodeT ) );
    temp->state = nw;
    temp->next = NULL;

    if( *head )
    {                                                                                            //if the node doesn't respect the conditions (more cannibals than normals on left/right bank) then dump it
        if( ( nw->c[LEFT] > nw->m[LEFT] ) || ( nw->c[RIGHT] > nw->m[RIGHT] ) || ( ( nw->c[LEFT] + nw->c[RIGHT] + nw->c[BOAT] ) > numP ) || ( ( nw->m[LEFT] + nw->m[RIGHT] + nw->m[BOAT] ) > numP ) ) //or if it uses other people than the initial ones, dumb it too
            { free( temp ); return; }

        if ( ( (*head)->state->c[RIGHT] + (*head)->state->m[RIGHT] ) < ( nw->c[RIGHT] + nw->m[RIGHT] ) )  //insert the new node before the head
        {
            temp->next = *head;
            (*head) = temp;
        }
        else                                                                                 //or find where to insert it, depending on the priority condition (the total nr of man taken on the right bank)
        {
            while ( start->next != NULL && ( (*head)->state->c[RIGHT] + (*head)->state->m[RIGHT] ) < ( nw->c[RIGHT] + nw->m[RIGHT] ) )
                start = start->next;
            temp->next = start->next;
            start->next = temp;
        }
    }
    else                   //if the queue was empty
        (*head) = temp;
}

//check if the queue is empty
int isEmpty( StateNodeT* head )
{
    return ( head == NULL );
}

//allocate a new node
StateT* newNode( StateT* parent, int side, int cleft, int mleft, int cright, int mright, int cboat, int mboat )
{
    StateT* node = (StateT*)malloc( sizeof( StateT ) );    //allocate memory for the node
    node->parent = parent;                                 //to trace the road to the final answer

    node->c[LEFT] = cleft;                    //cannibals on the left bank
    node->m[LEFT] = mleft;                    //normals on the left bank
    node->c[RIGHT] = cright;                  //cannibals on the right bank
    node->m[RIGHT] = mright;                  //normals on the right bank
    node->c[BOAT] = cboat;                    //cannibals on the boat
    node->m[BOAT] = mboat;                    //normals on the boat
    node->side = side;                        //to see where to boat is going (LEFT=to the left bank, RIGHT=to the right bank)

    return node;
}


/// CANNIBALS ///

//trace the path from root node to answer node
void printT( FILE* out, StateT* root )
{
    if ( root == NULL )
        return;
    printT( out, root->parent );

    fprintf( out, "L: %dc %dn\n", root->c[LEFT], root->m[LEFT] );
    fprintf( out, "B: %dc %dn\n", root->c[BOAT], root->m[BOAT] );
    fprintf( out, "R: %dc %dn\n", root->c[RIGHT], root->m[RIGHT] );

    fprintf( out, "\n" );
}

void Move ( FILE* out, int numP, int capacity )
{
    StateT* root = newNode( NULL, LEFT, numP, numP, 0, 0, 0, 0 );      //initialize the root node with all the people on the left bank

    StateNodeT* pq = NULL;                                         //initialize the priority queue
    push( &pq, root, numP );                                       //push root to queue of live nodes;

    while( !isEmpty( pq ) )
    {
        StateT* min = top( &pq );                               //find the most suitable node, pop it from the queue
        pop( &pq );

        if ( min->c[LEFT] == 0 && min->m[LEFT] == 0 )            //if min is an answer node, print the path to answer and the destination
        {
            printT( out, min );
            fprintf( out, "L: %dc %dn\n", 0, 0 );
            fprintf( out, "B: %dc %dn\n", 0, 0 );
            fprintf( out, "R: %dc %dn\n", numP, numP );
            return;
        }

        if( min->side == LEFT )                             //add all the possible ways of transporting people from left bank to the right bank
        {
            for( int cTr = (capacity / 2 != 0) ? ( capacity / 2 ) : 1; cTr >= 0; cTr-- )
            for( int mTr = (capacity / 2 != 0) ? ( capacity / 2 ) : 1; mTr >= 0; mTr-- )
                if( cTr + mTr >= 1 && ( mTr >= cTr || mTr == 0 ) )                          //the boat needs at least 1 person to go and there can't be more cannibals on the boat than normals
                {
                    StateT* child = newNode( min, RIGHT, min->c[LEFT] + min->c[BOAT] - cTr, min->m[LEFT] + min->m[BOAT] - mTr, min->c[RIGHT], min->m[RIGHT], cTr, mTr );
                    push( &pq, child, numP );
                }
        }
        if( min->side == RIGHT )                            //add all the possible ways of transporting people from right bank to the left bank (this is when the boat goes back to the left people on the left bank, but it can't go alone)
        {
            for( int cTr = 0; cTr < capacity / 2 || cTr <= 1; cTr++ )
            for( int mTr = 0; mTr < capacity / 2 || mTr <= 1; mTr++ )
                if( cTr + mTr >= 1 && ( mTr >= cTr || mTr == 0 ) )                       //the boat needs at least 1 person to go and there can't be more cannibals on the boat than normals
                {
                    StateT* child = newNode( min, LEFT, min->c[LEFT], min->m[LEFT], min->c[RIGHT] + min->c[BOAT] - cTr, min->m[RIGHT] + min->m[BOAT] - mTr, cTr, mTr );
                    push( &pq, child, numP );
                }
        }
    }
    free( pq );
}

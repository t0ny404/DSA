#include <stdio.h>
#include <stdlib.h>
#include "BranchAndBound.h"

/// read ///

CoordT readM ( FILE* in, long long* tile )
{
    CoordT table;                                       //structure to hold the coordinates of the empty tile
    long long digit;
    long long hex = 1;
    (*tile) = 0;

    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++ )
        {
            fscanf( in, "%I64u", &digit );              //%I64u is used for reading long long unsigned
            (*tile) += digit * hex;                     //I represent the nr in hexa; each digit of the long long variable represents a tile (from 0=empty to 15)
            hex *= 16;
            if( digit == 0 )
                table.x = i, table.y = j;
        }

    return table;
}


/// Priority Queue ///

//remove the node with the highest priority from the queue
Node* top( pQueue** head )
{
    return (*head)->data;
}
void pop( pQueue** head )
{
    pQueue* temp = *head;
    (*head) = (*head)->next;
    free( temp );
}

//push according to priority
void push( pQueue** head, Node* nw )
{
    pQueue* start = (*head);
    pQueue* temp = (pQueue*)malloc( sizeof( pQueue ) );
    temp->data = nw;
    temp->next = NULL;

    if( *head )
        if ( ( (*head)->data->cost + (*head)->data->level ) > ( nw->cost + nw->level ) )       //insert the new node before the head
        {
            temp->next = *head;
            (*head) = temp;
        }
        else                                                                                 //or find where to insert it, depending on the priority condition
        {
            while ( start->next != NULL && ( ( start->next->data->cost + start->next->data->level ) > ( nw->cost + nw->level ) ) )
                start = start->next;
            temp->next = start->next;
            start->next = temp;
        }
    else                                                                                    //if the queue was empty
        (*head) = temp;
}

//check if the queue is empty
int isEmpty( pQueue* head )
{
    return ( head == NULL );
}


/// PERSPICO ///

//print a matrix obtained from a long long variable
void printM( FILE* out, long long tile )
{
    for ( int i = 0; i < N; i++ )
    { for ( int j = 0; j < N; j++ )
            fprintf( out, "%I64u ", ( tile & 15 ) ), tile = tile >> 4;   //print tile%16, then divide tile by 16 (printing a digit of an hexa number)
        fprintf( out, "\n" );
    }
    fprintf( out, "-----------");
}

//trace the path from root node to answer node
void printT( FILE* out, Node* root )
{
    if ( root == NULL )
        return;
    printT( out, root->parent );
    printM( out, root->tile );

    fprintf( out, "\n" );
}

//find tile on (x, y) coordinates in a long long variable
long long pos( long long tile, int x, int y )
{
     tile = tile >> 4 * ( x * N );
     for ( int j = 0; j < y; j++ )              //initially I used that formula instead of using a loop, but as the x and y got higher, it returned 0 instead of the required value
                tile = tile >> 4;
    return tile & 15;                          //return ( tile & ( ( 1 << ( 4 * ( x * N + y + 1 ) ) ) - 1 ) ) >> ( 4 * ( x * N + y ) );
}

//allocate a new node
Node* newNode( long long tile, int x, int y, int newX, int newY, int level, Node* parent )
{
    Node* node = (Node*)malloc( sizeof( Node ) );
    node->parent = parent;

    node->tile = tile;                                    //copy data from parent node to current node

    long long swap = pos( node->tile, newX, newY);        //move tile
    node->tile += ( swap << 4*( x * N + y  ) );
    node->tile -= ( swap << 4*( newX * N + newY  ) );

    node->cost = INT_MAX;                                //initialize the nr of tiles not in their place and the depth of the tree to destination
    node->level = level;

    node->x = newX;                                     //update new blank tile coordinates
    node->y = newY;

    return node;
}

//calculate the nr of tiles not in their place
int costCalc( long long initial, long long finall )
{
    int nr = 0;
    for ( int i = 0; i < N; i++ )
      for ( int j = 0; j < N; j++ )
        {
            if (  ( initial & 15 ) != ( finall & 15 ) )
                nr++;
            initial = initial >> 4;
            finall = finall >> 4;
        }
    return nr;
}

//check if we are still in the matrix
int isIn( int x, int y )
{
    return ( x >= 0 && x < N && y >= 0 && y < N );
}

void Perspico( FILE* out, long long initial, int x, int y, long long finall )
{
    row[DOWN] = 1; col[DOWN] = 0;                                //all possible moves of the tile
    row[UP] = -1; col[UP] = 0;
    row[RIGHT] = 0; col[RIGHT] = 1;
    row[LEFT] = 0; col[LEFT] = -1;

    Node* root = newNode( initial, x, y, x, y, 0, NULL );         //create a root node and calculate its cost
    root->cost = costCalc( initial, finall );

    pQueue* pq = NULL;                                            //initialize the priority queue
    push( &pq, root );                                            //push root to queue of live nodes;

    while ( !isEmpty( pq ) )                                      //find the node with least cost, pop it from the queue
    {
        Node* min = top( &pq );
        pop( &pq );

        if ( min->cost == 2 )                                    //if min is an answer node, print the path to answer
        {                                                        //2 = if we do the next move(2 tiles are changed in a move) then we reached the final configuration
            printT( out, min );
            printM( out, finall );
            return;
        }

        for ( int i = DOWN; i <= LEFT; i++ )                      //we only have 4 possible moves( up, down, left, right) => 4 children of node min
            if ( isIn( min->x + row[i], min->y + col[i] ) )      //create a new node, calculate the cost and push it to queue of live nodes
            {
                Node* child = newNode( min->tile, min->x, min->y, min->x + row[i], min->y + col[i], min->level + 1, min );
                child->cost = costCalc( child->tile, finall );
                push( &pq, child );
            }
    }
    free( pq );
}

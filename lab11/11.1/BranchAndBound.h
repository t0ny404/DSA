#ifndef BRANCHANDBOUND_H_INCLUDED
#define BRANCHANDBOUND_H_INCLUDED

#define N 4

enum{ DOWN, UP, RIGHT, LEFT };                      //all the possible moves
int row[4], col[4];

typedef struct node {                               //structure to hold the tiles' table at each step

    struct node* parent;                            // stores the parent node of the current node for tracing path when the answer is found
    long long tile;                                 // stores tiles' positions
    int x, y;                                     // stores empty tile coordinates
    int cost;                                    // stores the number of tiles not in the supposed place
    int level;                                  // stores the number of moves so far

} Node;

typedef struct Q {                          //the priority queue

    Node* data;
    struct Q* next;

} pQueue;

typedef struct {                            //structure to hold the coordinates of the empty tile

    int x;
    int y;

} CoordT;

CoordT readM ( FILE* in, long long* tile );
void Perspico( FILE* out, long long initial, int x, int y, long long finall );

#endif // BRANCHANDBOUND_H_INCLUDED

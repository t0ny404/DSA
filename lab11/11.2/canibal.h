#ifndef CANIBAL_H_INCLUDED
#define CANIBAL_H_INCLUDED

enum { LEFT, RIGHT, BOAT };

typedef struct st {                 //structure to hold the current situation of the moving of the people

    struct st* parent;              //to trace the road to the final answer
    int m[3];                        //normals on the left/right bank and boat
    int c[3];                       //cannibals on the left/right bank and boat
    int side;                       //to see where to boat is going (LEFT=to the left bank, RIGHT=to the right bank)

} StateT;

typedef struct statenode {          //structure to hold all the situations, priority queue

    struct statenode* next;
    StateT* state;

} StateNodeT;

void Move ( FILE* out, int numP, int capacity );

#endif // CANIBAL_H_INCLUDED

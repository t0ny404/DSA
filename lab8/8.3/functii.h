#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

typedef enum {false, true} bool;

typedef struct {                    //structure to represent a worker

    int T;                          //available time
    int X;                          //hiring cost
    int Y;                          //speed (units of house/time unit)
    bool paid;                      //if the man was paid once it is 1, otherwise 0; in order not to be paid twice
    float productivity;             //speed/monetary unit

} WorkerT;

void init( int n, WorkerT man[n], FILE* in );
int Repaint( int n, int D, WorkerT man[n] );

#endif // FUNCTII_H_INCLUDED

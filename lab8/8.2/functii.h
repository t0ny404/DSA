#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

typedef enum { false, true } bool;

typedef struct{

    unsigned int name;              //the activity
    unsigned int s;                 //its start time
    unsigned int f;                 //its finish time
    bool compatible;                //adding to the set of compatible events

} ActivityT;

void init( int n, ActivityT A[n], FILE* in );
void Greedy( int n, ActivityT A[n] );
void printActivities( int n, ActivityT A[n], FILE* out );

#endif // FUNCTII_H_INCLUDED

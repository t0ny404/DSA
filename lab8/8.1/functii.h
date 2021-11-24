#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

enum{ zero_one, Fractional };
enum{ Weight, Value, Density };

typedef struct {

    float w;                 //weight
    float v;                 //value
    float density;          //value density

} ItemT;

void init( int n, ItemT itm[n], FILE* in );
void afisGreedy( int n, int W, ItemT itm[n], int caz, FILE* out );

#endif // FUNCTII_H_INCLUDED

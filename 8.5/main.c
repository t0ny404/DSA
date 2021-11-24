#include <stdio.h>
#include <stdlib.h>

int sum(int N, int K, int tape[N], int poz)
{
    int s = 0;
    for(int i=poz; i<=poz + K; i++)
        s += tape[i];
    return s;
}

int augment(int N, int K, int D, int tape[N])
{
    int op = 0, i = 0;

    while(i<=(N-K))
    {
        if(sum(N, K, tape, i) < D)
        {
            tape[i+K-1] += D;
            op++;
        }
        i++;
    }
    return op;
}

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int N, K, D;
    fscanf(in, "%d %d %d", &N, &K, &D);

    int tape[N];
    for(int i=0; i<N; i++)
        fscanf(in, "%d ", &tape[i]);
    int op = augment(N, K, D, tape);

    if(op)
        fprintf(out, "%d", op);
    else fprintf(out, "%d", -1);


    return 0;
}

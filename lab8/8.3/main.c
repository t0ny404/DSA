#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* in = fopen( argv[1], "r" );
    FILE* out = fopen( argv[2], "w" );

    if( !in ) perror( argv[1] );
    if( !out ) perror( argv[2] );

    int N, D;
    fscanf( in, "%d %d", &N, &D );

    WorkerT man[N];                              //array to hold the workers
    init( N, man, in );                          //read the workers( available time, hiring cost, speed)

    fprintf( out, "%d", Repaint( N, D, man ) );  //print the minimum cost for the painting of the house to finish as early as possible

    fclose( in );
    fclose( out );
    return 0;
}

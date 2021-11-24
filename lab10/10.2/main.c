// options are given on Project >> Set program's arguments as, e.g. -i input.txt -o output.txt
#include <stdio.h>
#include <stdlib.h>
#include "processArgs.h"
#include <unistd.h>
#include "functii.h"

int main ( int argc, char** argv )
{
    FILE *in  = NULL; //input stream
    FILE *out = NULL; //output stream

    if ( processArgs( argc, argv, &in, &out ) )
    {
        int N;                                                        //the nr of workers
        fscanf( in, "%d", &N );
        WorkerT w[N+1];                                                //the workers
        for( int i = 1; i <= N; i++ )
            fscanf( in, "%d %d", &w[i].engineer, &w[i].conductor );

        fprintf( out, "%d", opSalary( N, w ) );                        //minimal amount of money needed pay employees’ salaries
        //fprintf( out, "\n%d", opSalary2( N, w ) );

        if ( in != stdin )
        {
            fclose( in );
            in = NULL;
        }
    }
    else puts( "Failed to process arguments" );

    return 0;
}

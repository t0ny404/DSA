// options are given on Project >> Set program's arguments as, e.g. -i input.txt -o output.txt
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "processArgs.h"
#include <unistd.h>
#include "functii.h"

int main ( int argc, char** argv )
{
    FILE *in  = NULL; //input stream
    FILE *out = NULL; //output stream

    if ( processArgs( argc, argv, &in, &out ) )
    {
        int T;                  //test cases
        fscanf( in, "%d", &T );
        for( int i = 0; i < T; i++ )
        {
            char A[MAX_CH], B[MAX_CH];                //the 2 strings
            fscanf( in, "%s%s", A, B );
            fprintf( out, "%d\n",  NOP( A, B ) );   //the minimum nr of operations which turn string A into string B
        }

        if ( in != stdin )
        {
            fclose( in );
            in = NULL;
        }
    }
    else puts( "Failed to process arguments" );

    return 0;
}

// options are given on Project >> Set program's arguments as, e.g. -i input.txt -o output.txt
#include <stdio.h>
#include <stdlib.h>
#include "processArgs.h"
#include <unistd.h>
#include "canibal.h"

int main ( int argc, char** argv )
{
    FILE *in  = NULL; //input stream
    FILE *out = NULL; //output stream

    if ( processArgs( argc, argv, &in, &out ) )
    {
        int n, k;                           //nr of cannibals and capacity of boat (>=4)
        fscanf( in, "%d %d", &n, &k );

        Move( out, n, k );                  //function to move the n cannibals and n normals from the left bank to the right bank using a boat with capacity k, following the rules

        if ( in != stdin )
        {
            fclose( in );
            in = NULL;
        }
    }
    else puts( "Failed to process arguments" );

    return 0;
}

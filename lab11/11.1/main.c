// options are given on Project >> Set program's arguments as, e.g. -i input.txt -o output.txt
#include <stdio.h>
#include <stdlib.h>
#include "processArgs.h"
#include <unistd.h>
#include "BranchAndBound.h"

int main ( int argc, char** argv )
{
    FILE *in  = NULL; //input stream
    FILE *out = NULL; //output stream

    if ( processArgs( argc, argv, &in, &out ) )
    {

        long long initial, finall;                                  //the initial and final configuration of the table
        CoordT table;                                               //coordinates of the empty tile
        table = readM( in, &initial );
        readM( in, &finall );

        Perspico( out, initial, table.x, table.y, finall );         //the game

        if ( in != stdin )
        {
            fclose( in );
            in = NULL;
        }
    }
    else puts( "Failed to process arguments" );

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functii.h"

 //find maximum of two integer values
int max( int x, int y )
{
    return ( x > y )? x : y;
}

//find the length of the longest common subseq between the 2 strings
int LCS( char* x, char* y )
{
    int m = strlen(x);
    int n = strlen(y);
    int cost[m+1][n+1];

// initialize column zero
    for( int i = 0; i <= m; ++i )
        cost[i][0] = 0;
// initialize row zero
    for( int j = 0; j <= n; ++j )
        cost[0][j] = 0;

    for( int i = 1; i <= m; ++i )
    {
        for( int j = 1; j <= n; ++j )
        {
            if( x[i - 1] == y[j - 1] )
                // current character match
                cost[i][j] = cost[i - 1][j - 1] + 1;
            else if( cost[i - 1][j] > cost[i][j - 1] )
                // skip char from first string
                cost[i][j] = cost[i - 1][j];
            else
                // skip char from second string
                cost[i][j] = cost[i][j - 1];
        }
    }
    return cost[m][n]; // The length of the longest substring is cost[m][n]
}

/* min Nr of OPerations to turn first string into the second, is obtained by finding the longest common subseq between them,
and replacing all the other letters that don't belong to the LCS
or inserting letters if the first string has fewer letters
or deleting letters if it has more
=> ( max{|A|,|B|} - |LCS| ) operations */

int NOP( char* x, char* y )
{
    return max( strlen(y), strlen(x) ) - LCS( x, y );
}

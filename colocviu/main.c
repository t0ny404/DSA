/** I computed difference between 2 strings as mininum Nr of OPerations to turn first string into the second;
this is obtained by finding the longest common subseq between them,
and replacing all the other letters that don't belong to the LCS
or inserting letters if the first string has fewer letters
or deleting letters if it has more
=> ( max{|A|,|B|} - |LCS| ) operations;
than I chose the word in the dictionary with minimum difference from the query word
if this difference is 0 than the word is in dictionary too
if this is 1 than one letter is missing, or 1 too much or the order of two adjacent  letters is wrong compared to the word in dictionary
if this is >=2 then the word could not be found or resembled with the words from the dictionary
**/

// options are given on Project >> Set program's arguments as, e.g. -i input.txt -o output.txt
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "processArgs.h"
#include <unistd.h>
#include "dictionary.h"

int main ( int argc, char** argv )
{
    FILE *in  = NULL; //input stream
    FILE *out = NULL; //output stream

    if ( processArgs( argc, argv, &in, &out ) )
    {
        int nD, nQ;                                 //the nr of words in the dictionary and query
        fscanf( in, "%d", &nD );

        ListT* dictionaryL = CreateEmpty();          //dictionary list

        char buf[26];

        for( int i = 0; i < nD; i++ )
        {
            fscanf( in, "%s", buf );
            insertt( dictionaryL, buf );      //insert words in the dictionary
        }

        fscanf( in, "%d", &nQ );

        ListT* queryL = CreateEmpty();           //query words list

        for( int i = 0; i < nQ; i++ )
        {
            fscanf( in, "%s", buf );
            insertt( queryL, buf );             //insert words in the query to be checked
        }

        misspelling( out, dictionaryL, nD, queryL, nQ );    //check each word in the query

        if ( in != stdin )
        {
            fclose( in );
            in = NULL;
        }
    }
    else puts( "Failed to process arguments" );

    return 0;
}

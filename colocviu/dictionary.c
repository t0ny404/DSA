#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

/// LIST ///

ListT* CreateEmpty () {                                             //create an empty dictionary/query

    ListT* listptr = (ListT*)malloc( sizeof( ListT ) );
    if (listptr)
    {
        listptr->count = 0;
        listptr->first = listptr->last = NULL;
    }
    return listptr;
}

NodeT* CreateNode ( char w[26] ) {                             //make a word node

    NodeT* p = (NodeT*)malloc( sizeof( NodeT ) );
    if (p)
    {
        strcpy( p->word, w );
        p->next = p->prev = NULL;
    }
    return p;
}

void insertt ( ListT* listptr, char w[26] ) {               //insert a word into the list and check if it's already present

    NodeT* Next = listptr->first;
    NodeT* Prev = NULL;
    NodeT* p = CreateNode( w );

    while ( Next )
    {
        if ( stricmp( Next->word, w) == 0 )
        {
            Prev = Next;
            Next = Next->next;
        }
        Prev = Next;
        Next = Next->next;
    }

    if ( !( Next && strcmp( Next->word, w ) == 0 ) )
    {
        if ( !listptr || listptr->count == 0 )
            listptr->first = listptr->last = p;

        else
        {
            if( Prev == NULL )
            {
                p->next = listptr->first;
                listptr->first->prev = p;
                listptr->first = p;
            }
            else if ( Next )
            {
                p->next = Next;
                p->prev = Prev;
                Prev->next = p;
                Next->prev = p;
            }
            else
            {
                p->next = Next;
                p->prev = Prev;
                Prev->next = p;
                listptr->last = p;
            }
        }
            listptr->count++;
    }
}



/// LCS ///

int max( int x, int y )                         //find maximum of two integer values
{
    return ( x > y )? x : y;
}

int LCS( char* s1, char* s2 )                     //find the length of the longest common subseq between the 2 strings
{
    int m = strlen( s1 );
    int n = strlen( s2 );
    int cost[m+1][n+1];

    for( int i = 0; i <= m; ++i )               //initialize column zero
        cost[i][0] = 0;
    for( int j = 0; j <= n; ++j )               //initialize row zero
        cost[0][j] = 0;

    for( int i = 1; i <= m; ++i )
    {
        for( int j = 1; j <= n; ++j )
        {
            if( s1[i - 1] == s2[j - 1] )                      //current character match
                cost[i][j] = cost[i - 1][j - 1] + 1;
            else if( cost[i - 1][j] > cost[i][j - 1] )        //skip char from first string
                cost[i][j] = cost[i - 1][j];
            else                                            //skip char from second string
                cost[i][j] = cost[i][j - 1];
        }
    }
    return cost[m][n];                          //length of the longest substring is cost[m][n]
}

/* difference between 2 strings = mininum Nr of OPerations to turn first string into the second;
this is obtained by finding the longest common subseq between them,
and replacing all the other letters that don't belong to the LCS
or inserting letters if the first string has fewer letters
or deleting letters if it has more
=> ( max{|A|,|B|} - |LCS| ) operations */

int NOP( char* s1, char* s2 )
{
    return max( strlen( s2 ), strlen( s1 ) ) - LCS( s1, s2 );
}


/// MISSPELLING ///

BoolT sameLetters( char* s1, char* s2 )                     //function to check if the strings are formed of the same letters
{
    if( strlen( s1 ) != strlen( s2 ) )
        return FALSE;
    for( int i = 0; i < strlen( s2 ); i++ )
        if( strchr( s1, s2[i] ) == NULL )
        return FALSE;
    return TRUE;
}

void misspelling( FILE* out, ListT* dictionaryL, int nD, ListT* queryL, int nQ )
{
    NodeT* q = queryL->first;

    char corect[26];                    //the correct form of the word in query
    int lookalike, min;

    for( int i = 0; i < nQ; i++ )
    {
        NodeT* d = dictionaryL->first;
        min = NOP( d->word, q->word );                      //initialize min with the differences between the word in query and the first word in dictionary
        strcpy( corect, d->word );
        d = d->next;

        for( int j = 1; j < nD; j++ )
        {
            lookalike = NOP( d->word, q->word );            //find how similar are the words
            if( lookalike < min )                           //find the most similar word in the dictionary (the one with the least differences)
            {
                min = lookalike;
                strcpy( corect, d->word );
            }
            if( sameLetters( d->word, q->word ) == TRUE && min != 0 && min == strlen( q->word ) - 1 )  //find if the order of 2 adjacent letters is wrong
            {
                min = -1;
                strcpy( corect, d->word );
                j = nD;
            }
            d = d->next;                //go to next word in dictionary
        }

        if( min == 0 )                  //if the word in query is identical to one of the words in dictionary
            fprintf( out, "%s is correct\n", q->word );
        if( min >= 2 )                  //if we couldn't find a similar word in the dictionary for the word in query
            fprintf( out, "%s is unknown\n", q->word );
        if( min == 1 || min == -1 )     //if the word in query has one letter wrong than a word in dictionary or one letter is missing or 1 too much or adjacent letters are wrong
            fprintf( out, "%s is a misspelling of %s\n", q->word, corect );

        q = q->next;                    //go to next word in query
    }
}

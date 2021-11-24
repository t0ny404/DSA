#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLIT 1000

int main()
{
    FILE* in = fopen( "intrare.txt", "r" );

    if( !in ) perror( "intrare.txt" );

    char prevC = '.', prev2C = '.';
    char* word= (char*)malloc( sizeof( char ) * MAXLIT );
    char* buf = (char*)malloc( sizeof( char ) * 2 );
    int i = 0;

    fgets( buf, 2, in );
    while( ( buf[0] <= 122 && buf[0] >= 32 ) )
    {

        //pb 3

            if( strchr( ".!", prev2C ) != NULL )
                if( word[i-1] <= 'z' && word[i-1] >= 'a' )
                word[i-1] = toupper( word[i-1] );
                else word[i-1] = word[i-1];

            else
                if( word[i-1] <= 'Z' && word[i-1] >= 'A' )
                word[i-1] = tolower( word[i-1] );
                else word[i-1] = word[i-1];

        //pb 2
        if( prevC <= 'z' && prevC >= 'A' )
        {
            if( buf[0] == '0' )
                buf[0] = 'o';
            if( buf[0] == '7' )
                buf[0] = 'z';
        }
        else if( prevC <= '9' && prevC >= '0' )
        {
            if( buf[0] <= 'z' && buf[0] >= 'A' && i > 0 )
            {
                if( word[i-1] == '0' )
                    word[i-1] = 'o';
                if( word[i-1] == '7' )
                    word[i-1] = 'z';
            }
            word[i] = buf[0];
        }

        //pb 1
        if( buf[0] == ' ' || buf[0] == ',' )
        {
           int virgule = 0;
            while( buf[0] == ' ' || buf[0] == ',' )
            {
                fgets( buf, 2, in );
                if( buf[0] == ',' ) virgule = 1;
            }
            if( virgule == 1 )
                word[i] = ',';
            else i--;

            word[++i] = ' ';
            word[++i] = buf[0];
        }
        else {
                prev2C = buf[0];
                word[i] = buf[0];
        }

        prevC = buf[0];
        i++;
        fgets( buf, 2, in );
    }

    printf( "%s", word );

    return 0;
}

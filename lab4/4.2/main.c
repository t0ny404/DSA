#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* fin = fopen( argv[1], "r");
    FILE* finNode = fopen( argv[2], "r");
    FILE* foutI = fopen( argv[3], "w");
    FILE* foutH = fopen( argv[4], "w");
    FILE* foutL = fopen( argv[5], "w");

    if( !fin ) perror( argv[1] );
    if( !finNode ) perror( argv[2] );
    if( !foutI ) perror( argv[3] );
    if( !foutH ) perror( argv[4] );
    if( !foutL ) perror( argv[5] );

    printf( "tree(nodes=characters, empty spaces='*') should be given in '%s'\nthe node where the interchange is made should be given in '%s'\n", argv[1], argv[2] );

    NodeT* root = createBinTree( fin );

    int h = height( root );
    fprintf( foutH, "as number of nodes: %d\nas number of edges: %d", h, ( h - 1 >= 0 ) ? ( h - 1 ) : 0 );
    fprintf( foutL, "%d", leaves( root ) );

    char id;
    fscanf( finNode, "%c", &id );
    root = interchange( root, id );
    printTree( root, foutI );

    fclose( fin );
    fclose( finNode );
    fclose( foutI );
    fclose( foutH );
    fclose( foutL );

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functii.h"

int main( int argc, char* argv[] )
{
    FILE* fin = fopen( argv[1], "r" );
    FILE* fout = fopen( argv[2], "w" );
    if ( !fin ) perror( argv[1] );
    if ( !fout ) perror( argv[2] );

    BSTNode* root = NULL;
    char key, buff;
    BSTNode* p = (BSTNode*)malloc( sizeof( BSTNode ) );

    while( fscanf( fin, "%c", &buff ) != -1 )
        switch( buff )
    {
    case 'i':
        {
            fscanf( fin, "%c", &key );
            root = Insert( root, key, fout );
            break;
        }
    case 'd':
        {
            fscanf( fin, "%c", &key );
            root = deleteNode( root, key, fout );
            break;
        }
    case 'f':
        {
            fscanf( fin, "%c", &key );
            Find( root, key, fout );
            break;
        }
    case 't':
        {
            fscanf( fin, "%c", &key );
            fprintf( fout, "\n" );
            switch( key )
            {
                case 'p': preorder( root, 0, fout ); break;
                case 'P': postorder( root, 0, fout ); break;
                case 'i': inorder( root, 0, fout ); break;
            }
            break;

        }
    case 'g':
        {
            fscanf( fin, "%c", &key );
            switch( key )
            {
                case 'm':
                    {
                        p = findMin( root );
                        fprintf( fout, "\nMin is %c\n", p->key );
                        break;
                    }
                case 'M':
                    {
                        p = findMax( root );
                        fprintf( fout, "\nMax is %c\n", p->key );
                        break;
                    }
            }
            break;
        }
    }
    return 0;
}

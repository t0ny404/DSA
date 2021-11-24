#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functii.h"
#include "functii2.h"

int main( int argc, char* argv[] )
{
    FILE* fin = fopen( argv[1], "r" );
    FILE* fout = fopen( argv[2], "w" );
    if( !fin )
        perror( argv[1] );
    if( !fout )
        perror( argv[2] );

    BSTNode* root = NULL;
    char buff;

    while( fscanf( fin, "%c", &buff ) != -1 )
        switch( buff )
        {
        case 'i':
        {
            BSTNode* p = (BSTNode*)malloc( sizeof( BSTNode ) );
            p->left = p->right = NULL;

            faraVirgula( fin );
            strcpy( p->name, name );

            fscanf( fin, "%f", &(p->price) );
            fscanf( fin, "%*c%d", &(p->amount) );
            fscanf( fin, "%*c%ld", &(p->dateOfManufacturing) );
            fscanf( fin, "%*c%ld", &(p->dateOfExpiration) );

            root = Insert( root, p, fout );
            delTree( p );

            break;
        }
        case 'd':
        {
            faraVirgula( fin );
            root = deleteNode( root, name, fout );
            break;
        }
        case 'u':
        {
            faraVirgula( fin );
            root = update( root, Find( root, name, fout), fin, fout );
            break;
        }
        case 't':
        {
            char key;
            fscanf( fin, "%c", &key );
            fprintf( fout, "\n" );
            switch( key )
            {
            case 'p':
                preorder( root, 0, fout );
                break;
            case 'P':
                postorder( root, 0, fout );
                break;
            case 'i':
                inorder( root, 0, fout );
                break;
            }
            fprintf( fout, "\n" );
            break;

        }
        case 'c':
        {
            fscanf( fin, "%*c");

            BSTNode* ce = NULL;
            ce = expired( ce, root, fout );

           if( ce ) { fprintf( fout, "expired products are:\n"); inorder(ce,0,fout); } else fprintf( fout, "no expired products");
        }
        }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii2.h"

int main()
{
    Tree* tree = createBinTree();
    inorder( tree,0);
    return 0;
}

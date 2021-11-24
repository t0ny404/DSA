#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int main (int argc, char* argv[])
{
    FILE* fin = fopen (argv[1], "r");
    FILE* fout = fopen (argv[2], "w");

    if (!fin) perror(argv[1]);
    if (!fout) perror(argv[2]);

    int n;
    fscanf(fin, "%d", &n);

    char name[n][50];

    for( int i = 1; i <= n; i++)
        fscanf(fin, "%s", name[i]);

    List* listptr = CreateList(n);

    fprintf(fout, "%s", name[winner(listptr, n)]);

    fclose(fin);
    fclose(fout);

    return 0;
}


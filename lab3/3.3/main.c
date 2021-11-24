#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main (int argc, char* argv[])
{
    List* listptr = CreateEmpty();
    if (!listptr) printf("error");

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");

    if (!fin) perror(argv[1]);
    if (!fout) perror(argv[2]);

    int n;

    while (fscanf(fin, "%d", &n) != EOF)
        insertAt(listptr, n);

    afis(fout, listptr, listptr->first);
    fprintf(fout, "\n");
    afis(fout, listptr, listptr->last);

    return (0);
}

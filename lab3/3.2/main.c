#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int main (int argc, char* argv[])
{
    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");

    if (!fin) perror(argv[1]);
    if (!fout) perror(argv[2]);

    List* listptr = CreateEmpty();

    char buf[255];

    while (fscanf(fin, "%s", buf) != EOF)
        insertInOrder(listptr, buf);

    ascending(listptr, fout);
    fprintf(fout, "\n");
    descending(listptr, fout);

    fclose(fin);
    fclose(fout);

    return 0;
}

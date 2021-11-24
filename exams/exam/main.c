#include <stdio.h>
#include <stdlib.h>

int main()
{
   int A[] ={0, 1, 1, 1, 5, 10, 25, 25 };
   int sum=0;

    for( int i = 1; i <= 7; i++ )
        sum=sum+A[i];
    int amounts[20000] ={0};

    for(int i = 1; i<= 7; i++ )
    {
        for(int j =sum; j>=1; j-- )
        if(amounts[j] == 1)
        amounts[j+A[i]]=1;

        amounts[A[i]]=1;
    }
int i;
    for(i=1; i<=sizeof(amounts); i++)
        if( amounts[i]==0)
        {
            printf("%d\n", i );
            break;
        }

    int count = 0;

    for( int j=i; j<=sum; j++ )
        if(amounts[j]==0)
        count++;

    printf( "%d   %d", sum, count);

    return 0;
}

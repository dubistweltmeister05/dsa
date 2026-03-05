#include <stdio.h>
#include <stdlib.h>

int main()
{

    int test[] = {1, 1, 1, 1, 2, 3, 5};

    int candidate = -1;
    int vote = 0;

    for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        if (vote == 0)
        {
            candidate = test[i];
            vote = 1;
        }

        if (test[i] == candidate)
            vote++;
        else
            vote--;
    }
    int count = 0;
    for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        if (test[i] == candidate)
            count++;
    }
    printf( "%d", (count>((sizeof(test) / sizeof(test[0])/2)))?count:-1);

    // return 0;
}
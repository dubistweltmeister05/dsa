#include <stdio.h>

int main()
{
    int test[] = {1, 1, 1, 1, 2, 3, 5};
    int n = sizeof(test) / sizeof(test[0]);

    int candidate = -1;
    int vote = 0;

    for (int i = 0; i < n; i++)
    {
        if (vote == 0)
            candidate = test[i];

        if (test[i] == candidate)
            vote++;
        else
            vote--;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        if (test[i] == candidate)
            count++;

    printf("%d\n", (count > n / 2) ? candidate : -1);

    return 0;
}
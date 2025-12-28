#include <stdio.h>
void main()
{
    int a[] = {50, 60, 40, 70, 20, 10, 100, 30, 80, 90}, i, max;
    max = a[0];
    for (i = 1; i < 10; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    printf("Maximum element in the array is: %d\n", max);
}
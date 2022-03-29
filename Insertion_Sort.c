#include <stdio.h>

int main()
{
    int n, a[10], i, j, key, swap=0, comp=0;

    printf("\n\tINSERTION SORT");

    printf("\n\nEnter array size: ");
    scanf("%d", &n);

    printf("\nEnter array elements:\n");
    for(i=1; i<=n; i++)
    {
        printf("Array element %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nUnsorted array: ");

    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }

    for(j=2; j<=n; j++)
    {
        key = a[j];
        i = j-1;

        while(i>0 && ++comp && a[i]>key)
        {
            a[i+1] = a[i];
            i = i-1;
            swap++;
        }
        a[i+1] = key;
    }

    printf("\n\nThe sorted array is: ");

    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nNo. of swaps: %d", swap);

    printf("\n\nNo. of comparisons: %d\n", comp);

    return 0;
}

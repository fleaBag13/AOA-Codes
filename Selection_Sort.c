#include<stdio.h>

int main()
{
    int n, i, j, k, flag, a[10], swap=0, comp=0;

    printf("\n\tSELECTION SORT");

    printf("\n\nEnter no. of elements in the array: ");
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

    for(i=1; i<=n; i++)
    {
        j = i;

        for(k=i+1; k<=n; k++)
        {
            if(a[k] < a[j])
            {   j = k;  }
            comp++;
        }

        flag = a[i];
        a[i] = a[j];
        a[j] = flag;
        swap++;
    }

    printf("\n\nSorted array: ");

    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nNo. of swaps: %d", swap);

    printf("\n\nNo. of comparisons: %d\n", comp);
}














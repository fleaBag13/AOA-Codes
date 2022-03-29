#include <stdio.h>
int q, x, j, i, p, r, temp, a[10], n, m=0, temp2, c=0;
int partition(int a[], int p, int r)
{
x = a[r];
i = p-1;
for(j=p; j<=(r-1); j++)
{
if(a[j]<=x)
{
i = i + 1;
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
temp2 = a[i+1];
a[i+1] = a[r];
a[r] = temp2;
return (i+1);
}
void quicksort(int a[], int p, int r)
{
if(p<r)
{
q = partition(a, p, r);
c++;
quicksort(a, p, q-1);
c++;
quicksort(a, q+1, r);
}
}
int main() {
printf("Enter no. of array elements: ");
scanf("%d", &n);
printf("\nEnter array elements: \n");
for(m=0; m<n; m++)
{
printf("Array element %d: ", (m+1));
scanf("%d", &a[m]);
}
printf("\nArray entered: ");
for(m=0; m<n; m++)
{
printf("%d ", a[m]);
}

p = 0;
r = n-1;
c++;
quicksort(a,p,r);
printf("\n\nSorted array: ");
for(m=0; m<n; m++)
{
printf("%d ", a[m]);
}
printf("\nNo. of calls to the quicksort function: %d", c);
return 0;
}

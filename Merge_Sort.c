#include <stdio.h>
int c=0, low, high;

void merge(int arr[], int low, int high)
{
    int mid = (low + high)/2;
    int len1 = mid - low + 1;
    int len2 = high - mid;

    int arr1[len1];
    int arr2[len2];

    int k = low;
    for(int i=0;i<len1;i++)
    {
        arr1[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for(int i=0;i<len2;i++)
    {
        arr2[i] = arr[k];
        k++;
    }

    int index1 = 0;
    int index2 = 0;
    k = low;

    while(index1<len1 && index2<len2)
    {
        if(arr1[index1] < arr2[index2])
        {
          arr[k] = arr1[index1];
          index1 ++;
          k++;
        }
        else
        {
            arr[k] = arr2[index2];
            index2++;
            k++;
        }
    }

    while(index1 < len1){
        arr[k] = arr1[index1];
        index1 ++;
        k++;
    }

      while(index2 < len2){
        arr[k] = arr2[index2];
        index2 ++;
        k++;
    }
}

void mergeSort(int arr[],int low, int high){
   if(low<high)
    {
       int mid = (low+high)/2;
       c++;
       mergeSort(arr,low,mid);
       c++;
       mergeSort(arr,mid+1,high);
       merge(arr,low,high);
   }
}

void main(){
    int arr[10];
    int n, i;

    printf("\n\tMerge Sort\n\nEnter n: ");
    scanf("%d", &n);

    printf("\nArray elements: \n");
    for(i=0; i<n; i++)
    {
        printf("Enter element %d: ", (i+1));
        scanf("%d", &arr[i]);
    }

    low=0;
    high=n-1;

    c++;
    mergeSort(arr,low,high);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n\nNo. of calls to MergeSort function: %d\n", c);

}

#include <stdio.h>
#include <math.h>

int main()
{
    int  n, i, remc, obj[i], j, count=0;
    float temp, temp2, temp3, temp4, ratio[10], kcap, x[10], xi[10], wi[10], item[10], val=10;

    printf("Enter the knapsack capacity: ");
    scanf("%f", &kcap);

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("\n");
    for(i=1; i<=n; i++)
    {
        printf("Enter the weight of object %d: ", i);
        scanf("%f", &wi[i]);
    }

    printf("\n");
    for(i=1; i<=n; i++)
    {
        printf("Enter the value of object %d: ", i);
        scanf("%f", &xi[i]);
    }

    for(i=1; i<=n; i++)
    {
        obj[i] = i;
    }

    printf("\nObject\tWeight\t\tValue\n");
    for(i=1; i<=n; i++)
    {
        printf("%d\t%f\t%f\n", obj[i], wi[i], xi[i]);
    }

    for(i=1; i<=n; i++)
    {
        ratio[i] = xi[i]/wi[i];
    }

    printf("\nCalculating ratio: ");
    printf("\nObject\tWeight\t\tValue\t\tRatio\n");
    for(i=1; i<=n; i++)
    {
        printf("%d\t%f\t%f\t%f\n", obj[i], wi[i], xi[i], ratio[i]);
    }

    printf("\nSorting");
    for(i=1; i<n; i++)
    {
        for(j=1; j<=n-i; j++)
       {
          if(ratio[j+1]>ratio[j])
          {
              temp = ratio[j];
              ratio[j] = ratio[j+1];
              ratio[j+1] = temp;

              temp2 = wi[j];
              wi[j] = wi[j+1];
              wi[j+1] = temp2;

              temp3 = xi[j];
              xi[j] = xi[j+1];
              xi[j+1] = temp3;

              temp4 = obj[j];
              obj[j] = obj[j+1];
              obj[j+1] = temp4;
          }
       }
    }

    printf("\nObject\tWeight\t\tValue\t\tRatio\n");
    for(i=1; i<=n; i++)
    {
        printf("%d\t%f\t%f\t%f\n", obj[i], wi[i], xi[i], ratio[i]);
    }

    for(i=1; i<=n; i++)
    {
        x[i] = 0;
    }

    remc = kcap;
    //remc2 = kcap;

    /*for(i=1; i<=n; i++)
    {
        if(wi[i]<=remc2)
        {
            remc2 = remc2 - wi[i];
            item[i] = wi[i];
        }
        if(remc2==0)
        {
            break;
        }
    }*/

    for(i=1; i<=n; i++)
    {
        if(wi[i]>=remc)
        {
            break;
        }
        x[i] = 1;
        remc = remc - wi[i];
        item[i] = obj[i];
        val += xi[i];
        count++;
    }

    if(i<=n)
    {
        x[i] = remc/wi[i];
        count++;
        item[i] = obj[i];
        val += x[i]*xi[i];
    }

    printf("\nItems in the knapsack are: ");
    for(j=1; j<=count; j++)
    {
        printf("%f ", item[j]);
    }
    printf(" %f", x[i]);

    printf("\nFinal Value: %f\n", val);

    return 0;
}

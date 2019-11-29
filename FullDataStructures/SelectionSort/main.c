//selection_sort
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[1000],n,min,j,i,temp;
    printf("enter size :\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[min])
            {
                min=j;
            }
        }
        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
    
    printf("Array after sorting:\n");
    for(i=0;i<n;i++)
        printf("%d ",array[i]);
    return 0;
    
}

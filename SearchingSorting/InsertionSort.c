//insertionSort
# include <stdio.h>
int main()
{
    int n,A[100],i,j,key;
    printf("Enter size:\n");
    scanf("%d",&n);
    printf("ENter Elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    for (i=0;i<n-1;i++)
    {
        j = i;
        key = A[i+1];
        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1]= key;
    }
    printf("Array after sorting is:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}

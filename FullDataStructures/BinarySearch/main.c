//
//  main.c
//  binary search
//
//  Created by Vicky_Jha on 24/11/19.
//  Copyright © 2019 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int search ,first , last,mid;
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    first = 0;
    last = sizeof(arr)/sizeof(arr[0]);
    //    printf("%d",last);
    printf("Enter the element to be searched\n");
    scanf("%d",&search);
    
    while(first <= last)
    {
        mid = (first + last)/2;
        if(search < arr[mid])
            last = mid - 1;
        else if(search > arr[mid])
            first = mid + 1;
        else if(search == arr[mid])
        {
            printf("Element %d found at location %d\n",search,mid+1);
            exit(1);
        }
    }
    printf("Element %d not found\n",search);
    return 0;
}

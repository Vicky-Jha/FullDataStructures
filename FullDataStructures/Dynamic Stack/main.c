dynami_stack
//
//  main.c
//  stackPrac
//
//  Created by Vicky_Jha on 26/10/19.
//  Copyright © 2019 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#define MAX 5;
int top = -1;
struct stack
{
    int *A;
    int MAX_SIZE;
    int size;
    int *B;
    
};
struct stack *pt;
void newStack(int size)
{
    pt = (struct stack*)malloc(sizeof(struct stack));//what is the need?
    pt -> A = (int*)calloc(size , sizeof(int));
    pt -> MAX_SIZE = size;
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if(top == pt -> MAX_SIZE - 1)
        return 1;
    else
        return 0;
    
}
void push()
{
    int n;
    if(isFull())
    {
        printf("Stack is FUll\n");
    }
    else
    {
        printf("Enter an element to push\n");
        scanf("%d",&n);
        top++;
        pt -> A[top] = n;
        printf("Element entered \n");
    }
    
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else{
        top--;
        printf("Element Popped\n");
    }
    
}

void Top()
{
    
    printf("%d\n",pt -> A[top]);
    
}
void display()
{
    if(isEmpty())
    {
        printf("Empty\n");
    }
    else{
        printf("Stack is :\n");
        for(int i = top;i >= 0; --i)
        {
            printf("%d\n",pt -> A[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice;
    int sz,newSize;
    printf("Enter Max Size of Stack\n");
    scanf("%d",&sz);
    newStack(sz);
    
    printf("Enter your choice\n1 for Push\n2 for Pop\n3 for Top element\n4 for Display\n5 exit\n6 to Change MaxSize of Stack\n");
    while(1)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:Top();
                break;
            case 4:display();
                break;
            case 5:exit(0);
                break;
            case 6:printf("Enter New Max Size of the Stack\n");
                scanf("%d",&newSize);
                if(newSize>0)
                {
                    if(newSize < pt -> MAX_SIZE)
                    {
                        for (int i=0;i<pt -> MAX_SIZE - newSize;i++)
                            top--;
                        //                pt -> B = (int*)realloc(pt -> A, newSize*sizeof(int));
                        pt -> MAX_SIZE = newSize;
                        
                    }
                    else
                        //            pt -> B = (int*)realloc(pt -> A, newSize*sizeof(int));
                        pt -> MAX_SIZE = newSize;
                }
                else
                    printf("Size cannot be 0 or negative\n");
                break;
            default:printf("Invalid Option\n");
                break;
        }
    }
    return 0;
}

//
//  main.c
//  test
//
//  Created by Vicky_Jha on 23/11/19.
//  Copyright © 2019 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int arr[MAX];
int top = -1;
void push(void);
void pop(void);
void peek(void);
void traverse(void);
int isEmpty(void);
int isFull(void);

int main(int argc, const char * argv[]) {
    int ch;
    while (1)
    {
        
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.traverse\n");
        printf("5.isEmpty\n");
        printf("6.isFull\n");
        printf("7.Quit\n");
        
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        
        switch (ch)
        {
                
            case 1 : push();
                break;
            case 2 : pop();
                break;
            case 3 : peek();
                break;
            case 4 : traverse();
                break;
            case 5 : if(isEmpty())
                printf("Empty\n");
            else
                printf("Not empty\ncurrent size: %d\n",top+1);
                break;
            case 6:if(isFull())
                printf("Full\n");
            else
                printf("Not Full\ncurrent size: %d\n",top+1);
                break;
            case 7:exit(1);
                break;
            default : printf("Invalid input\n\n");
                break;
        }
    }
}
void push()
{
    if(!isFull())
    {
        int n;
        printf("Enter an element to push:\n");
        scanf("%d",&n);
        top++;
        arr[top] = n;
        printf("Element %d Pushed\n",n);
    }
    else
        printf("Overflow\n");
}
void pop()
{
    if(!isEmpty())
    {
        printf("Element %d Popped\n",arr[top]);
        top--;
    }
    else
        printf("Underflow\n");
}
void peek()
{
    printf("Top element is %d\n",arr[top]);
}
void traverse()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n",arr[i]);
    }
}
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top == MAX)
        return 1;
    else
        return 0;
}

//debug this program and learn
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char stack[MAX],arr[MAX],x[100];
int top =-1;
void push(char);
void pop(void);
int main()
{
    printf("Enter a parenthesized expression\n");
    scanf("%s", &arr);
    printf("entered string is %s\n",arr);
    for (int i = 0 ;arr[i] != '\0' ; i++)
    {
        switch (arr[i]) {
            case '(': push(arr[i]);
                break;
            case ')': pop();
                break;
                
        }
        //        if(arr[i] == '(')
        //            push(arr[i]);
        //        else if(arr[i] == ')')
        //            pop();
    }
    if (top == -1)
    {
        printf("Expression is Valid\n");
    }
    else
    {
        printf("Expression is Invalid\n");
    }
    return 0;
}
void push(char x)
{
    top++;
    stack[top] = x;
}
void pop()
{
    top--;
}

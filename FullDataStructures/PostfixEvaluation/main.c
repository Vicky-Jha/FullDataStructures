//
//  main.c
//  postfixEvaluation
//
//  Created by Vicky_Jha on 24/11/19.
//  Copyright © 2019 test. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int stack[100],top = -1;
int pop()
{
    int a;
    a = stack[top];
    top--;
    return a;
}
void push(int value)
{
    top++;
    stack[top] = value;
}
int is_operand(char ch)
{
    if ((ch>='a' && ch<='z') || (ch>='A' && ch<='z'))
        return 1;
    else
        return 0;
}

int main(int argc, const char * argv[])
{
    int m,op1,op2,result = 0;//r
    char postfix[100],ch;//r
    printf("Enter an postfix expression\n");
    gets(postfix);
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        ch=postfix[i];
        if(is_operand(ch))
        {
            printf("Enter the value of %c :\n",ch);
            scanf("%d",&m);
            push(m);
        }
        else
        {
            op2 = pop();//r
            op1 = pop();//r
            switch (ch) {
                case '+':
                    result=op1+op2;
                    push(result);
                    break;
                case '-':
                    result=op1-op2;
                    push(result);
                    break;
                case '*':
                    result=op1*op2;
                    push(result);
                    break;
                case '/':
                    result=op1/op2;
                    push(result);
                    break;
                case '%':
                    result=op1%op2;
                    push(result);
                    break;
                    
                default:
                    break;
            }
        }
    }
    printf("Evaluated result of the above postfix expression is %d\n",result);
    return 0;
}

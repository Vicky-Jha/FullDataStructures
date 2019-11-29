//StackLinkedList
//
//  main.c
//  StackLinkedList
//
//  Created by test on 27/06/19.
//  Copyright © 2019 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *top = NULL;
void push();
void topp();
void displayList();
int size();
void pop();
void isEmpty();

int main() {
    int ch;
    while(1)
    {
        printf("Enter Your option:\n");
        printf("1 to insert data\n2 to print top data\n3 to display list of data\n4 to print size\n5 to remove top element\n6 to check if the list is empty or not\n7 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                break;
            case 2:topp();
                break;
            case 3:displayList();
                break;
            case 4:size();
                printf("Number of data are :%d \n",size());
                break;
            case 5:pop();
                break;
            case 6:isEmpty();
                break;
            case 7:exit(1);
                break;
            default:printf("Enter a valid option\n");
                break;
        }
    }
    return 0;
}

void push ()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of the node:\n");
    scanf("%d",&temp -> data);
    // temp -> next = NULL;
    temp -> next = top;
    top = temp;
    printf("Data %d is inserted successfully\n",temp->data);
}
void topp()
{
    if (top == NULL){
        printf("Empty List\n");
    }
    else
    {
        printf("%d\n",top -> data);
    }
}
int size()
{
    int count = 0;
    struct node *temp = top;
    if (top == NULL)
    {
        printf("List is Empty:\n");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp -> next;
            count++;
        }
    }
    return count;
}
void displayList()
{
    struct node *temp = top;
    int length = size();
    if(temp == NULL){
        printf("List is Empty:\n\n");
    }
    else
    {
        while(length--)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("\n\n");
    }
    
}
void pop(){
    if(top == NULL){
        
        printf("List is EMPTY , 1st Enter Data then Pop\n");
    }
    else{
        printf("Top Data %d Deleted Successfully\n",top -> data);
        struct node *temp = top;
        top = temp -> next;
        temp -> next = NULL;
        free(temp);
    }
    
}
void isEmpty()
{
    if(top == NULL){
        printf("Empty\n");
    }
    else
    {
        printf("Not Empty\n");
    }
}

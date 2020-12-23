//
//  main.c
//  CircularQueueLinked
//
//  Created by Vicky_Jha on 26/11/19.
//  Copyright © 2019 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct cqueueLL
{
    int data;
    struct cqueueLL *next;
};
struct cqueueLL *front = NULL , *rear = NULL;
void enqueue()
{
    struct cqueueLL *temp = (struct cqueueLL*)malloc(sizeof(struct cqueueLL)),store;
    printf("Enter the data\n");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    if(rear == NULL && front == NULL)
    {
        front = rear = temp;
        temp -> next = front;
    }
    
    else
    {
        rear -> next = temp;
        temp -> next = front;
        rear = temp;
    }
    
}
void dequeue()
{
    if ( front == NULL)
    {
        printf("Queue empty\n");
    }
    else
    {
        struct cqueueLL *temp = front ;
        front = temp -> next;
        free(temp);
    }
}
void display()
{
    struct cqueueLL *temp = front;
    if (front == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        while(temp->next != front)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("%d ",rear -> data );
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    int ch;
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                
            default:printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

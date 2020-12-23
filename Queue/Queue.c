#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int A[MAX_SIZE];
int front = -1, rear = -1;

int IsEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
        return 0;
}

int IsFull()
{
    if ((rear+1) % MAX_SIZE == front)
    {
        return 1;
    }
    else
        return 0;
}

void Enqueue(int x)
{
    if(IsFull())
    {
        printf("Error: Queue is Full\n");
        return;
    }
    if (IsEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1) % MAX_SIZE;
    }
    A[rear] = x;
}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("Error: Queue is Empty\n");
        return;
    }
    else
    {
        front = (front+1) % MAX_SIZE;
    }
}
int Front()
{
    if(front == -1)
    {
        printf("Error: empty queue\n");
        return -1;
    }
    return A[front];
}
int QueueSize()
{
    int count =-1;
    count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
    return count;
}
void Print()
{
    int count = QueueSize();
    printf("Queue is as follows : ");
    for(int i = 0; i <count; i++)
    {
        int index = (front+i) % MAX_SIZE;
        printf("%d ",A[index]);
    }
    printf("\n\n");
}

int main()
{
    int ch,n;
    printf("Enter your choice\n");
    while (1)
    {
        printf("1 to insert element\n2 to delete Element\n3 to return front element\n4 to find size of queue\n5 to check if queue is empty or full\n6 to Display elements\n7 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter data to be inserted\n");
                scanf("%d",&n);
                Enqueue(n);
                if(!IsFull())
                    printf("Data %d inserted Successfully\n",n);
                break;
            case 2:Dequeue();
                break;
            case 3:printf("%d\n",Front());
                break;
            case 4:printf("%d\n",QueueSize());
                break;
            case 5:if (IsEmpty() == 1)
                printf("Queue is Empty\n");
            else if (IsFull())
                printf("Queue is Full\n");
            else
                printf("Queue is not empty\n");
                break;
            case 6:Print();
                break;
            case 7:exit(1);
                break;
            default:printf("Enter Valid option\n");
                break;
        }
    }
    
    
}

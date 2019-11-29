#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *A;
    int MAX_SIZE;
    int front;
    int rear;
    int size;
    int *B;
    
};

struct queue* newQueue(int size)
{
    struct queue *pt = NULL;
    pt = (struct queue*)malloc(sizeof(struct queue));
    
    pt->A = (int*)malloc(size * sizeof(int));
    pt->MAX_SIZE = size;
    pt->front = -1;
    pt->rear = -1;
    
    return pt;
}

int IsEmpty(struct queue *pt)
{
    if (pt -> front == -1 && pt -> rear == -1)
    {
        return 1;
    }
    else
        return 0;
}

int IsFull(struct queue *pt)
{
    if ((pt -> rear+1) % pt -> MAX_SIZE == pt -> front)
    {
        return 1;
    }
    else
        return 0;
}

void Enqueue(int x , struct queue *pt)
{
    if(IsFull(pt))
    {
        printf("Error: Queue is Full\n");
        return;
    }
    if (IsEmpty(pt))
    {
        pt -> front = pt -> rear = 0;
    }
    else
    {
        pt -> rear = (pt -> rear+1) % pt -> MAX_SIZE;
    }
    pt -> A[pt -> rear] = x;
}

void Dequeue(struct queue *pt)
{
    if(IsEmpty(pt))
    {
        printf("Error: Queue is Empty\n");
    }
    else if(pt -> front == pt -> rear )
    {
        pt -> rear = pt -> front = -1;
    }
    else
    {
        pt -> front = (pt ->front+1) % pt -> MAX_SIZE;
    }
}
int Front(struct queue *pt)
{
    if(pt -> front == -1)
    {
        printf("Error: empty queue therefore returning ");
        return -1;
    }
    
    return pt -> A[pt -> front];
}
int QueueSize(struct queue *pt)
{
    if (IsEmpty(pt))
        return 0;
    int count =-1;
    count = (pt -> rear + pt -> MAX_SIZE - pt -> front) % pt -> MAX_SIZE + 1;
    return count;
}
void Print(struct queue *pt)
{
    if(IsEmpty(pt))
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        int count = QueueSize(pt);
        printf("Queue is as follows : ");
        for(int i = 0; i <count; i++)
        {
            int index = (pt -> front+i) % pt -> MAX_SIZE;
            printf("%d ",pt -> A[index]);
        }
    }
    //        printf("\n%d",count);
    printf("\n\n");
}

int main()
{
    int sz,newSize;
    printf("Enter Max Size of Array\n");
    scanf("%d",&sz);
    struct queue *pt = newQueue(sz);
    int ch,n;
    printf("Enter your choice\n");
    while (1)
    {
        printf("1 to insert element\n2 to delete Element\n3 to return front element\n4 to find size of queue\n5 to check if queue is empty or full\n6 to Display elements\n7 to change Max size\n8 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter data to be inserted\n");
                scanf("%d",&n);
                Enqueue(n,pt);
                if(!IsFull(pt))
                    printf("Data %d inserted Successfully\n",n);
                break;
            case 2:Dequeue(pt);
                break;
            case 3:printf("%d\n",Front(pt));
                break;
            case 4:printf("%d\n",QueueSize(pt));
                break;
            case 5:if (IsEmpty(pt) == 1)
                printf("Queue is Empty\n");
            else if (IsFull(pt))
                printf("Queue is Full\n");
            else
                printf("Queue is not empty\n");
                break;
            case 6:Print(pt);
                break;
            case 7:printf("Enter New Max Size of the array\n");
                scanf("%d",&newSize);
                pt -> B = (int*)realloc(pt -> A, newSize*sizeof(int));
                pt -> MAX_SIZE = newSize;
                
                //                struct queue *pt = newQueue(newSize);
                break;
            case 8:exit(1);
                break;
            default:printf("Enter Valid option\n");
                break;
        }
    }
    
    
}

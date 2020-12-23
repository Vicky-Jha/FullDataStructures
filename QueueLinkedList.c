//Linked List
//final
#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue *next;
};
struct Queue *head = NULL;

void EnQueue(void);
int QueueSize(void);
void displayList(void);
void DeQueue(void);
void Front(void);
int IsEmpty(void);

int main()
{
    int ch;
    while(1)
    {
        printf("Enter Your Choice:\n");
        printf("1 to insert element\n2 to delete Element\n3 to find size of queue\n4 to check if queue is empty or full\n5 to print front element\n6 to Display elements\n7 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:EnQueue();
                break;
            case 2:DeQueue();
                break;
            case 3:printf("%d\n",QueueSize());
                break;
            case 4:printf("%d",IsEmpty());
                printf("\n");
                break;
            case 5:Front();
                break;
            case 6:displayList();
                break;
            case 7:exit(1);
                break;
            default:printf("Invalid Option, try again:\n");
                break;
        }
    }
}

void EnQueue()
{
    struct Queue *temp = (struct node*)malloc(sizeof(struct Queue));
    printf("Enter data :\n");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Queue *p = head;
        while (p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = temp;
    }
    printf("Data %d is successfully inserted\n",temp->data);
}


int QueueSize()
{
    int count = 0;
    struct Queue *temp = head;
    if (head == NULL)
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
    struct Queue *temp = head;
    int length = QueueSize();
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
void DeQueue()
{
    if (head == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        struct Queue *temp = head;
        head = temp -> next;
        temp -> next = NULL;
        free(temp);
    }
}
int IsEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Front()
{
    if (!IsEmpty())
        printf("Front element is %d \n",head -> data);
    else
        printf("Queue is Empty\n");
}

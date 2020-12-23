//Array Queue
# include <stdio.h>
# include <stdlib.h>
# define max 5

int front = 0, rare = 0,data,stack[max];
void Enqueue(void);
void Dequeue(void);
void Display(void);
int Full(void);
int Empty(void);
void initialize(void);

int main()
{
    int ch;
    while(1)
    {
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                Enqueue();
                break;
            case 2:Dequeue();
                break;
            case 3:Display();
                break;
            case 4:initialize();
                break;
            case 5:exit(1);
                break;
                
            default:printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
int Full()
{
    if(rare == max)
        return 1;
    else
        return 0;
}
int Empty()
{
    if(rare == front)
        return 1;
    else
        return 0;
}
void Enqueue()
{
    if(Full())
        printf("Queue is Full\n");
    else
    {
        printf("Enter Queue data\n");
        scanf("%d",&data);
        stack[rare] = data;
        rare++;
    }
    
}
void Dequeue()
{
    if(Empty())
        printf("queue is Empty\n");
    else
    {
        printf("Data %d is Deleted\n",stack[front]);
        for (int i=front;i<rare;i++)
        {
            stack[i] = stack[i+1];
        }
        rare--;
    }
}
void Display()
{
    if(Empty())
        printf("Queue is Empty\n");
    else
    {
        for (int i = 0 ; i<rare ; i++)
        {
            printf("%d ",stack[i]);
        }
    }
}
void initialize()
{
    front = rare = 0;
}

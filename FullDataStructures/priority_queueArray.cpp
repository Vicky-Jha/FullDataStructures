//Array Queue
# include <bits/stdc++.h>
# define max 20
using namespace std;

int front = 0, rear = 0,ele,pq[max], i,j,temp,del;
int loc = 0,flag=0;
void Enqueue(void);
void Dequeue(void);
void Display(void);
int Full(void);
int Empty(void);
void findMin();

int main()
{
    int ch;
    while(1)
    {
		cout<<"Choose  Option \n";
		cout<<"1. Insert\n2. Delete\n3. Find Min\n4. Display\n5. Exit\n";
		
        scanf("%d",&ch);
        switch (ch) {
            case 1:Enqueue();
                break;
            case 2:Dequeue();
                break;
            case 3:findMin();
                break;
            case 4:Display();
                break;
            case 5:exit(0);
                break;
            default:printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
int Full()
{
    if(rear == max)
        return 1;
    else
        return 0;
}
int Empty()
{
    if(rear == front)
        return 1;
    else
        return 0;
}
void Enqueue() // Complexity O(n)
{
    if(Full())
        printf("Queue is Full\n");
    else
    {
        printf("Enter Queue data\n");
        scanf("%d",&ele);
        
        if( front == rear )
        {
			pq[front] = ele;
		}
		else if( front == rear - 1 )
		{
			if ( pq[front] > ele )
			{
			pq[rear] = pq[front];
			pq[front] = ele;
			}
			else
			pq[rear] = ele;
			
		}
		else if( ele >= pq[rear-1] )
		{
			pq[rear] = ele;
		}
		else
		{
        for ( i = front; i < rear; ++ i )
        {
			if ( ele <= pq[i] )
			{
				for ( j = rear - 1; j >= i; -- j )
					pq[j+1] = pq[j];
				pq[i] = ele;
				break;
			}
		}
		
		}
		cout<<"Data "<<ele<<" Inserted successfully\n";
		rear ++;
	}
    
}
void Dequeue() // complexity O(1)
{
    if(Empty())
        printf("queue is Empty\n");
    else
    {
        front ++;
    }
}
void Display()
{
    if(Empty())
        printf("Queue is Empty\n");
    else
    {
        for (i = front ; i<rear ; i++)
        {
            printf("%d ",pq[i]);
        }
    }
    cout<<"\n";
}
void findMin() //complexity O(1)
{
	if(!Empty())
	cout<<"Min is "<<pq[front]<<"\n";
	else
	cout<<"Queue is empty\n";
}


//Linked List
//final
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insertAtEnd(void);
void insertAtBegin(void);
int lengthOfNode(void);
void displayList(void);
void insertAtMiddle(void);
void deleteNodeByLocation(void);
void deleteFullList(void);
void NthNodeFromEnd(void);
void stackUsingLinkedList(void);
int NullTerminatedOrCircular(void);
void nthNodeFromEndOrBeginning(void);
void SortListInDecending(void);
void reverseList(void);
void deleteByData(void);
void sortAccending();

int main()
{
    int ch;
    while(1)
    {
        printf("Enter Your Choice:\n");
        printf("1 to Insert node at begining\n2 to insert at end\n3 to enter a node in the middle\n4 to count number of nodes in the list\n5 to display the nodes in the list\n6 to delete node by location \n7 to delete full list\n8 To find nth node from the beginning or end of the linked list\n9 To Check whether the given linked list is either NULL-Terminated or Ends in Cycle (Circular Linked list) also print starting node and length of Loop if Circular Linked List\n10 to sort the Nodes of List in Decending Order\n11 to Reverse Linked List\n12 Delete data\n13 Sort in Accending\n14 Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertAtBegin();
                break;
            case 2:insertAtEnd();
                break;
            case 3:insertAtMiddle();
                break;
            case 4:lengthOfNode();
                printf("Number of nodes in the list is = %d\n",lengthOfNode());
                break;
            case 5:displayList();
                break;
            case 6:deleteNodeByLocation();
                break;
            case 7:deleteFullList();
                break;
            case 8:nthNodeFromEndOrBeginning();
                break;
            case 9:NullTerminatedOrCircular();
                break;
            case 10:SortListInDecending();
                break;
            case 11:reverseList();
                break;
            case 12:deleteByData();
                break;
            case 13:sortAccending();
                break;
            case 14:exit(1);
            default:printf("Invalid Option, try again:\n");
                break;
        }
    }
}
void insertAtBegin()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of the node:\n");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp -> next = head;
        head = temp;
    }
    printf("Data %d is successfully inserted in the beginning\n",temp->data);
}
void insertAtEnd()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of the node:\n");
    scanf("%d",&temp -> data);
    temp -> next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p = head;
        while (p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = temp;
    }
    printf("Data %d is successfully inserted at the End\n",temp->data);
}
void insertAtMiddle()
{
    struct node *temp , *p;
    int loc , k = 1;
    
    printf("Enter the Location where you wish to enter node:\n");
    scanf("%d",&loc);
    
    if(loc > lengthOfNode())
    {
        printf("Location is Invalid\n");
        printf("Current length of List is = %d nodes\n",lengthOfNode());
    }
    else
    {
        p = head;
        while (loc > k)
        {
            p = p -> next;
            k++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data of the node:\n");
        scanf("%d",&temp -> data);
        temp -> next = NULL;
        temp -> next = p -> next;
        p -> next = temp;
    }
    // printf("Data %d is successfully inserted after location %d \n",temp->data,loc);
}
int lengthOfNode()
{
    int count = 0;
    struct node *temp = head;
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
    struct node *temp = head;
    int length = lengthOfNode();
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
void deleteNodeByLocation()
{
    int loc = 0;
    if (head == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        printf("Enter Location to delete the node\n");
        scanf("%d",&loc);
        if (loc > lengthOfNode())
        {
            printf("Location is Invalid\n");
            printf("Current length of List is = %d nodes\n",lengthOfNode());
        }
        else if (loc == 1)
        {
            struct node *temp = head;
            head = temp -> next;
            temp -> next = NULL;
            free(temp);
        }
        else
        {
            struct node *p , *q;
            p = head;
            int k=2;
            while (k < loc)
            {
                p = p -> next;
                k++;
            }
            q = p -> next;
            p -> next = q ->next;
            q -> next = NULL;
            free(q);
        }
    }
    printf("Node at location %d deleted successfully \n",loc);
}
void deleteFullList()
{
    if (head == NULL){
        printf("List is already Empty\n");
    }
    else
    {
        struct node *p , *i;
        i = head;
        while (i!=NULL)
        {
            p = i -> next;
            free(i);
            i = p;
            
        }
        printf("List Deleted successfully\n");
    }
}
/*void NthNodeFromEnd()
 {
 struct node *temp = head;
 int n,i=1;
 printf("Enter location of node from the end of a linked list\n");
 scanf("%d",&n);
 if (n>lengthOfNode())
 {
 printf("Current length of List is = %d nodes\nTry again\n",lengthOfNode());
 }
 else
 {
 while (i!=(lengthOfNode()-n+1))
 {
 temp = temp -> next;
 i++;
 }
 printf("nth node from the end of a linked list is = %d\n",temp -> data);
 }
 }*/
int NullTerminatedOrCircular()
{
    int LoopExist = 0, count =1;
    struct node *slow = head , *fast = head , *temp;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (slow && fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow->next == fast ->next)
            {
                LoopExist = 1;
                printf("Loop Exists\n");
                break;
            }
        }
        if (LoopExist)
        {
            slow = head;
            temp = fast;
            while (slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
            printf("Starting Node is = %d\n",slow ->data);
        }
        if (LoopExist)
        {
            while (slow != slow -> next)
            {
                count++;
            }
            printf("Length of the Loop is %d\n",count);
            return count;
        }
        else
        {
            printf("This Is NULL - Terminated Linked List\n");
        }
    }
    return 0;
}
void nthNodeFromEndOrBeginning()
{
    struct node *temp = head;
    int n,i=1;
    int ch;
    printf("Enter 1 to find nth node from the beginning\nEnter 2 to find nth node from the end\n");
    scanf("%d",&ch);
    switch (ch) {
        case 1:
            printf("Enter location of node from the beginning of the linked list\n");
            scanf("%d",&n);
            if (n>lengthOfNode())
            {
                printf("Current length of List is = %d nodes\nTry again\n",lengthOfNode());
            }
            else
            {
                while (i!=n)
                {
                    temp = temp -> next;
                    i++;
                }
                printf("nth node from the beginning of a linked list is = %d\n",temp -> data);
            }
            
            break;
        case 2:
            printf("Enter location of node from the end of the linked list\n");
            scanf("%d",&n);
            if (n>lengthOfNode())
            {
                printf("Current length of List is = %d nodes\nTry again\n",lengthOfNode());
            }
            else
            {
                while (i!=(lengthOfNode()-n+1))
                {
                    temp = temp -> next;
                    i++;
                }
                printf("nth node from the end of a linked list is = %d\n",temp -> data);
            }
            break;
            
        default:printf("Invalid Option\n");
            break;
    }
}
void SortListInDecending()
{
    for (int i = 1 ; i <= lengthOfNode() ; i++)
    {
        struct node *temp = head , *p = head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
            if (p -> data < temp -> data)
            {
                int store;
                store = temp -> data;
                temp -> data = p -> data;
                p -> data = store;
            }
            p = p -> next;
        }
    }
    printf("Nodes of List Sorted in decending order Successfully Enter 5 to display the sorted list\n");
}

void problem54()
{
    int length = lengthOfNode()/2;
    struct node *temp = head, *slow = head , *fast = head , *p, *c , *h;
    while (length--)
    {
        temp = temp -> next;
    }
    h = temp;
    
    if(h != NULL)
    {
        p = h;
        c = h->next;
        h = h -> next;
        
        p -> next = NULL;
        
        while(h != NULL)
        {
            h = h -> next;
            c -> next = p;
            
            p = c;
            c = h;
        }
        
        h = p;
    }
    
    while (slow && fast && fast -> next)
    {
        
    }
}
void reverseList()
{
    struct node *temp = head;
    int arr[lengthOfNode()];
    for(int i = 0 ; i<lengthOfNode() ; i++){
        arr[i] = temp -> data;
        temp = temp -> next;
    }
    for(int i = lengthOfNode() - 1 ; i >= 0 ; i--){
        printf("%d ",arr[i]);
    }
    //     struct node *p, *c;
    //     if(head == NULL)
    //     {
    //         printf("List is Empty:\n");
    //     }
    //     else
    //     {
    //         p = head;
    //         c = head->next;
    //         head = head -> next;
    
    //         p -> next = NULL;
    
    //         while(head != NULL)
    //         {
    //             head = head->next;
    //             c -> next = p;
    
    //             p = c;
    //             c = head;
    //         }
    
    //         head = p;
    
    //         printf("List Reversed Successfully\n");
    //     }
}
void deleteByData()
{
    int d,count=-1;
    printf("ENter data you wish to delete\n");
    scanf("%d",&d);
    struct node *traverse = head,*temp = head;
    if (d == temp -> data)
    {
        head = temp -> next;
        free(temp);
    }
    else
    {
        while (traverse && traverse -> data != d)
        {
            traverse = traverse -> next;
            count++;
        }
        while (count > 0)
        {
            temp = temp -> next;
            count -= 1;
        }
        temp -> next = traverse -> next;
        free(traverse);
    }
}
void sortAccending()
{
    struct node *temp = head,*temp1;
    int store;
    
    for(int i=0 ; i<lengthOfNode()-1 ; i++){
        temp = head;
        for(int j=0 ; j<lengthOfNode()-i-1 ; j++){
            temp1 = temp -> next;
            if(temp -> data > temp1 -> data){
                store = temp -> data;
                temp -> data = temp1 -> data;
                temp1 -> data = store;
            }
            temp = temp -> next;
        }
    }
}

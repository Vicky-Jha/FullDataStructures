
#include <stdio.h>
#include <stdlib.h>
struct LList
{
    int data;
    struct LList *next;
}*head = NULL;
int count(void);
void beforeHead(int );
void afterTail(int );
void insertInLinkedList(int , int );
void display(void);
void deleteNode(int );
void deleteLinkedList(void);
int main(int argc, const char * argv[]) {
    int data , ch , position;
    while(1)
    {
        printf("Enter your choice\n1.insert node in the beginning\n2.insert node at the end\n3.insert node by position\n4.display\n5.Delete a node by Position\n6.Delete Full list\n7.Exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter node data\n");
                scanf("%d",&data);
                beforeHead(data);
                break;
            case 2:
                printf("Enter node data\n");
                scanf("%d",&data);
                afterTail(data);
                break;
            case 3:
                printf("Enter position of the new node\n");
                scanf("%d",&position);
                printf("Enter node data\n");
                scanf("%d",&data);
                insertInLinkedList(data, position);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("ENter the position of the node to delete\n");
                scanf("%d",&position);
                deleteNode(position);
                break;
            case 6:
                deleteLinkedList();
                break;
            case 7:exit(1);
                break;
                
            default:printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
int count()
{
    int count=0;
    struct LList *temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void beforeHead(int data)
{
    struct LList *newNode = (struct LList*)malloc(sizeof(struct LList));
    newNode->data = data;
    newNode->next = NULL;
    if(!newNode){
        printf("Memory error\n");
        return;
    }
    if(head == NULL)
        head = newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
}
void afterTail(int data)
{
    struct LList *newNode = (struct LList*)malloc(sizeof(struct LList)),*temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if(!newNode){
        printf("Memory error\n");
        return;
    }
    if(head == NULL)
        head = newNode;
    else{
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
void insertInLinkedList(int data , int position)
{
    struct LList *p, *newNode , *c;
    newNode = (struct LList*)malloc(sizeof(struct LList));
    if(!newNode){
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    p = head;
    if(position == 1){
        newNode->next = p;
        head = newNode;
    }
    else{
        if(position > count()+1)
        {
            printf("Entered position of newNode is Invalid\nCurrent size of List = %d\n",count());
            return;
        }
        else
        {
            position--;
            while(position--){ //number of loops = position
                c = p;
                p = p->next;
            }
            newNode->next = p;
            c->next = newNode;
        }
    }
}
void display()
{
    struct LList *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else{
        while (temp) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void deleteNode(int position)
{
    struct LList *p = head,*c;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else{
        if(position == 1){
            head = p->next;
            free(p);
            return;
        }
        else{
            if(position > count())
            {
                printf("Entered position of newNode is Invalid\nCurrent size of List = %d\n",count());
                return;
            }
            else
            {
                position--;
                while(position--){ //number of loops = position
                    c = p;
                    p = p->next;
                }
                c->next = p->next;
                free(p);
//                free(c);
            }
        }
    }
}
void deleteLinkedList()
{
    struct LList *iterator = head , *temp;
    while (iterator) {
        temp = iterator->next;
        free(iterator);
        iterator = temp;
    }
    head = NULL;
}

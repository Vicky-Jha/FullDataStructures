
#include <stdio.h>
#include <stdlib.h>
struct CLList
{
    int data;
    struct CLList *next;
}*front = NULL , *rear = NULL;
int count(void);
void beforeHead(int );
void afterTail(int );
void insertInCLinkedList(int , int );
void display(void);
void deleteNode(int );
void deleteCLinkedList(void);
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
                insertInCLinkedList(data, position);
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
                deleteCLinkedList();
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
    struct CLList *temp = front;
    while(temp){
        count++;
        temp = temp->next;
        if(temp == front)
            break;
    }
    return count;
}

void beforeHead(int data)
{
    struct CLList *newNode = (struct CLList*)malloc(sizeof(struct CLList));
    newNode->data = data;
    newNode->next = NULL;
    if(!newNode){
        printf("Memory error\n");
        return;
    }
    if(front == NULL){
        front = rear = newNode;
    rear->next = front;
    }
    else{
        newNode->next = front;
        front = newNode;
        rear->next = front;
    }
}
void afterTail(int data)
{
    struct CLList *newNode = (struct CLList*)malloc(sizeof(struct CLList)),*temp = front;
    newNode->data = data;
    newNode->next = NULL;
    if(!newNode){
        printf("Memory error\n");
        return;
    }
    if(front == NULL){
        front = rear = newNode;
        rear->next = front;
    }
    else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}
void insertInCLinkedList(int data , int position)
{
    struct CLList *p, *newNode , *c;
    newNode = (struct CLList*)malloc(sizeof(struct CLList));
    if(!newNode){
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    p = front;
    if(position == 1){
        newNode->next = p;
        front = newNode;
        rear->next = front;
    }
    else{
        if(position > count()+1)
        {
            printf("Entered position of newNode is Invalid\nCurrent size of List = %d\n",count());
            return;
        }
        else
        {
            int store = position;
            position--;
            while(position--){ //number of loops = position
                c = p;
                p = p->next;
            }
            newNode->next = p;
            c->next = newNode;
            if(store == count()+1)
            {
                rear = newNode;
            rear->next = front;
            }
        }
    }
}
void display()
{
    struct CLList *temp = front;
    if(front == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else{
        while (temp) {
            printf("%d ",temp->data);
            temp = temp->next;
            if(temp == front)
                break;
        }
    }
    printf("\n");
}
void deleteNode(int position)
{
    struct CLList *p = front,*c;
    if(front == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else{
        if(position == 1){
            front = p->next;
            rear->next = front;
            free(p);
            return;
        }
        else{
            if(position > count())
            {
                printf("Entered position of newNode is Invalid\nCurrent size of List = %d\n",count());
                return;
            }
            else if(position == count())
            {
                position--;
                while(position--){ //number of loops = position
                    c = p;
                    p = p->next;
                }
                c->next = rear->next;
                free(p);
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
void deleteCLinkedList()
{
    struct CLList *iterator = front , *temp;
    while (iterator) {
        temp = iterator->next;
        free(iterator);
        iterator = temp;
        if (iterator == front)
            break;
    }
    front = NULL;
}

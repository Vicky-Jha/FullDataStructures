
#include <stdio.h>
#include <iostream>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    
    if(x==-1)
        return NULL;
    
    p=(node*)malloc(sizeof(node));
    p->data=x;
    
    printf("Enter left child of %d:\n",x);
    p->left=create();
    
    printf("Enter right child of %d:\n",x);
    p->right=create();
    
    return p;
}

void preorder(node *t)        //address of root node is passed in t
{
    if(t!=NULL)
    {
        printf("\n%d",t->data);        //visit the root
        preorder(t->left);        //preorder traversal on left subtree
        preorder(t->right);        //preorder traversal om right subtree
    }
}

int Height(node *root)
{
    int leftHeight , rightHeight;
    if(root == NULL)
        return 0;
    else{
        leftHeight = Height(root -> left);
        rightHeight = Height(root -> right);
        
        if(leftHeight > rightHeight)
            return (leftHeight+1);
        else
            return (rightHeight+1);
    }
    
}

int main()
{
    node *root;
    root=create();
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\nHeight of Binary tree is \n");
    printf("%d\n",Height(root));
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
struct BSTnode
{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};
struct BSTnode *root = NULL;
int data1,count =0, store;
void printPreorder(struct BSTnode *root)
{
    struct BSTnode *temp = root;
    if (temp == NULL)
    {
        return;
    }
    if(temp)
    {
        printf("%d ", temp->data);//bad access
        
        printPreorder(temp->left);
        
        printPreorder(temp->right);
    }
}

void printInorder(struct BSTnode *root)
{
    if(root != NULL)
    {
        printInorder(root->left);
        
        printf("%d ", root->data);
        
        printInorder(root->right);
    }
}
void printPostorder(struct BSTnode *root)
{
    
    if (root == NULL)
    {
        return;
    }
    if(root)
    {
        printPostorder(root->left);
        
        printPostorder(root->right);
        
        printf("%d ", root->data);
        
    }
}
struct BSTnode* findMin(struct BSTnode *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

/*struct BSTnode *findMin(struct BSTnode *root)
 {
 struct BSTnode *temp = root;
 if (root == NULL)
 {
 return 0;
 }
 else
 {
 if (temp -> left == NULL)
 {
 printf("Minimum element in Binary tree is %d\n",temp -> data);
 }
 }
 return findMin(temp -> left);
 }*/
//int findMax(struct BSTnode *root)
//{
//    struct BSTnode *temp = root;
//    if (root == NULL)
//    {
//        printf("Tree Empty\n");
//        return -1;
//    }
//    else
//    {
//        while (temp -> right != NULL)
//        {
//            temp = temp -> right;
//        }
//        printf("Maximum element in Binary Search tree is %d\n",temp -> data);
//    }
//            return temp -> data;
//}
//
//

struct BSTnode *findMax(struct BSTnode *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
void nsertBSTnode()
{
    struct BSTnode *temp = (struct BSTnode*)malloc(sizeof(struct BSTnode)),*t = root;
    printf("Enter BSTnode data\n");
    scanf("%d",&temp -> data);
    temp -> left = NULL;
    temp -> right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        while (t)
        {
            if (temp -> data > t -> data)
            {
                t = t -> right;
            }
            else
            {
                t = t -> left;
            }
        }
        t = temp;
    }
}

void insertBSTnode()
{
    struct BSTnode *temp = (struct BSTnode*)malloc(sizeof(struct BSTnode)) , *p = root , *c;
    printf("Enter BSTnode Data\n");
    scanf("%d",&temp -> data);
    temp -> left = NULL;
    temp -> right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while (p)
        {
            c = p;
            if (temp -> data > p -> data)
            {
                p = p -> right;
                if(p == NULL)
                {
                    c -> right = temp;
                }
            }
            else
            {
                p = p -> left;
                if(p == NULL)
                {
                    c -> left = temp;
                }
            }
        }
        
    }
}
void searchElement(struct BSTnode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root)
    {
        if (root -> data == data1)
        {
            count++;
        }
        searchElement(root->left);
        
        searchElement(root->right);
    }
    //    struct BSTnode *temp = root;
    //    int data;
    //    printf("Enter the data to search within the binary tree\n");
    //    scanf("%d",&data);
    //    if (temp -> data == data)
    //    {
    //        printf("Found\n");
    //    }
    //    else if (temp -> data > data)
    //    {
    //        temp = temp -> right;
    //    }
}
int SizeOfBinaryTree(struct BSTnode *root)
{
    if (root == NULL)
        return 0;
    else
        return (SizeOfBinaryTree(root -> left)+ 1 + SizeOfBinaryTree(root -> right));
}
void Size()
{
    printf("Size of Binary search tree is %d\n",SizeOfBinaryTree(root));
}
void deleteTree(struct BSTnode *root)
{
    struct BSTnode *temp = root;
    if (temp == NULL)
        return;
    printf("Deleting node: %d", temp -> data);
    deleteTree(temp -> left);
    deleteTree(temp -> right);
    free(temp);
}
/*
 struct BSTnode *Delete(struct BSTnode *root , int data)
 {
 struct BSTnode *temp;
 if(root == NULL)
 printf("ELEMENT not there in tree\n");
 else if (data < root->data)
 root -> left = Delete(root->left, data);
 else if (data > root->data)
 root -> right = Delete(root -> right, data);
 else
 {
 if (root -> left && root -> right)
 {
 temp = findMax(root -> left);
 root -> data = temp -> data;
 root -> left = Delete(root -> left, root -> data);
 }
 else{
 temp = root;
 if (root->left == NULL)
 root = root -> right;
 if (root -> right == NULL)
 root = root -> left;
 free(temp);
 }
 }
 return root;
 }*/
struct BSTnode *Delete(struct BSTnode *root, int data) {
    if(root == NULL)
        printf("Tree is Empty\n");
    else if(data < root->data)
        root->left = Delete(root->left,data);
    else if(data > root->data)
        root-> right = Delete(root->right,data);
    else {
        // Case 1:  No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        //Case 2: One child
        else if(root->left == NULL) {
            struct BSTnode *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            struct BSTnode *temp = root;
            root = root->left;
            free(temp);
        }
        // case 3: 2 children
        else {
            struct BSTnode *temp = findMin(root->right);
            root->data = temp->data;
            root -> right = Delete(root->right,temp->data);
        }
    }
    return root;
}


int main()
{
    
    int ch , data;
    struct BSTnode *temp;
    while(1)
    {
        printf("ENTER YOUR CHOICE\n");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1:insertBSTnode();
                break;
            case 2:printf("\nPreorder traversal of binary tree is \n");
                printPreorder(root);
                printf("\n");
                break;
            case 3:printf("\nInorder traversal of binary tree is \n");
                printInorder(root);
                printf("\n");
                break;
            case 4:printf("\nPostorder traversal of binary tree is \n");
                printPostorder(root);
                printf("\n");
                break;
            case 5:temp = findMin(root);
                printf("Minimum element in Binary search tree is %d\n",temp -> data);
                break;
            case 6:temp = findMax(root);
                printf("Maximum element in Binary search tree is %d\n",temp -> data);
                break;
            case 7:Size();
                break;
            case 8:printf("Enter the data to search within the binary tree\n");
                scanf("%d",&data1);
                searchElement(root);
                if (SizeOfBinaryTree(root) == 0)
                {
                    printf("Tree Empty\n");
                }
                if (count == 0 && SizeOfBinaryTree(root)>0)
                {
                    printf("Element %d Not found in the BT\n",data1);
                }
                if (count > 0)
                {
                    printf("Element %d found %d times in this Binary tree\n",data1 , count);
                }
                break;
            case 9:deleteTree(root);
                root = NULL;
                printf("\nTree Deleted\n");
                break;
            case 10:
                printf("Enter data to delete from BST\n");
                scanf("%d",&data);
                Delete(root, data);
                break;
            default:printf("Enter Valid option\n");
                break;
        }
    }
    return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *insert()
{
    struct node *newNode;
    int data;

    printf("Enter data: ");
    scanf("%d",&data);

    if(data == -1) return NULL;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    printf("Enter value of left child of %d: \n",data);
    newNode->left = insert();

    printf("Enter the value of right child of %d: \n",data);
    newNode->right = insert();

    return newNode;
}

void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert();
    display(root);
}
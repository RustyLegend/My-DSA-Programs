#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
} *top = NULL;

struct node* nodeCreator()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}

void push()
{
    struct node* temp = nodeCreator();
    if (top == NULL) top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if (top == NULL) printf("\nStack is empty, Cannot pop an element.\n");
    else 
    {
        struct node* prev = top;
        printf("\nPopped element: %d\n",top->data);
        top = top->next;
        free(prev);
    }
}

void peek()
{
    if (top == NULL) printf("\nStack is empty\n");
    else printf("\nTop element: %d\n",top->data);
}

void display() 
{
    printf("The final stack is (from top to bottom): ");
    while (top!=NULL) 
    {
        printf("%d ",top->data);
        top = top->next;
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1 - Pushing an element\n2 - Popping an element\n3 - Peeking at the top\n4 - Print the final stack\n");
        scanf("%d",&ch);
        if(ch == 1) push();
        else if (ch == 2) pop();
        else if (ch == 3) peek();
        else if (ch == 4)
        {
            display();
            break;
        }
        else printf("Please enter a valid choice.");
    }
}
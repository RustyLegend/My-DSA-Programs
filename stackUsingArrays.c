#include<stdio.h>
#define max 20
int top = -1;
int arr[max];

void push(int n)
{
    if(top == max-1) printf("\nCan't add more elements to the stack.\n");
    else
    {
        top++;
        arr[top] = n;
    }
}

void pop()
{
    if(top == -1) printf("\nStack is empty, Cannot pop an element.\n");
    else
    {
        int popped_element = arr[top];
        printf("\nPopped element: %d\n",popped_element);
        top--;
    }
}

void peek()
{
    if(top == -1) printf("\nStack is empty\n");
    else printf("\nTop element: %d\n",arr[top]);
}

void display() 
{
    printf("\nThe final stack is (from top to bottom): ");
    for(int i = top ; i >= 0 ; i--) printf("%d ",arr[i]);
}

int main()
{
    while (1)
    {
        int ch;
        printf("\n1 - Pushing an element\n2 - Popping an element\n3 - Peeking at the top\n4 - Print the final stack\n");
        scanf("%d",&ch);
        if (ch == 1)
        {
            int data;
            printf("Enter data: ");
            scanf("%d",&data);
            push(data);
        }
        else if (ch == 2) pop();
        else if (ch == 3) peek();
        else if (ch == 4)
        {
            display();
            break;
        }
        else printf("\nPlease enter a correct value\n");
    }
}
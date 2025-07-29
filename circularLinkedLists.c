#include<stdio.h>
#include<stdlib.h>

int numberOfNodes = 0;

struct node 
{
    int data;
    struct node* next;
}*head = NULL , *current = NULL;

struct node* nodeCreator()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    numberOfNodes++;
    return temp;
}

void displayNode()
{
    current = head;
    while (current->next != head)
    {
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("%d",current->data);
    printf("\n");
}

int main()
{
    struct node *temp;
    char ch = 'Y';
    while (ch == 'Y' || ch == 'y')
    {
        temp = nodeCreator();
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            current -> next = temp;
        }
        current = temp;
        current->next = head;
        printf("Do you want to continue (y/n): ");
        scanf(" %c",&ch);
    }

    int choice;
    while (1)
    {
        printf("1 - Insert at beginning\n2 - Insert at the end\n3 - Insert at an intermediate position\n4 - Delete an element\n5 - Print the final list\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            temp = nodeCreator();
            temp->next = head;
            current = head;
            while (current -> next != head)
            {
                current = current->next;
            }
            head = temp;
            current->next = head;
        }
        else if (choice == 2)
        {
            temp = nodeCreator();
            current = head;
            while (current->next !=head)
            {
                current = current->next;
            }
            current->next = temp;
            temp->next = head;
        }
        else if (choice == 3)
        {
            int position;
            printf("Preview of the list: ");
            displayNode();
            printf("Enter the position you want to insert at (2 to %d): ",numberOfNodes);
            scanf("%d",&position);
            if (position > 1 && position <= numberOfNodes)
            {
                temp = nodeCreator();
                current = head;
                for (int i = 1 ; i < position-1 ; i++) current = current->next;
                temp -> next = current ->next;
                current->next = temp;
            }
            else printf("Invalid position.");
        }
        else if (choice == 4)
        {
            printf("1 - Delete the beginning element\n2 - Delete the ending element\n3 - Delete at an intermediate position\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                current = head;
                while (current->next != head) current = current->next;
                current->next = head->next;
                free(head);
                head = current->next;
                numberOfNodes -= 2;
            }
            else if (choice == 2)
            {
                current = head;
                while (current->next->next != head) current = current->next;
                free(current->next);
                current->next = head;
                numberOfNodes -= 2;
            }
            else if (choice == 3)
            {
                int position;
                displayNode();
                printf("Enter the position of the element you want to delete (2 to %d): ",numberOfNodes-1);
                scanf("%d",&position);
                if (position > 1 && position < numberOfNodes)
                {
                    current = head;
                    for (int i = 1 ; i < position - 1 ; i++) current = current->next;
                    struct node* del = current->next;
                    current->next = del->next;
                    free(del);
                    del = NULL;
                    numberOfNodes -= 2;
                }
            }
        }
        else if (choice == 5)
        {
            displayNode();
            break;
        }
        else
        {
            printf("Invalid choice.");
        }
    }
}
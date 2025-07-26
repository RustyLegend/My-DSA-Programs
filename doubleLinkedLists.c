#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
} *head = NULL , *tail = NULL , *temp = NULL , *current = NULL ;

int main()
{
    char ch = 'Y';
    int numberOfNodes = 0;
    while (ch == 'Y' || ch == 'y')
    {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&temp->data);
        temp->prev = NULL;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            current->next = temp;
            temp->prev = current;
        }
        current = temp;
        numberOfNodes++;

        printf("Do you want to continue (y/n): ");
        scanf(" %c",&ch);
    }
    tail = current;

    int insertChoice;
    while (1)
    {
        printf("1 - Insert at beginning\n2 - Insert at ending\n3 - Insert at a position\n4 - Print the final list\n");
        scanf("%d",&insertChoice);
        if(insertChoice == 1)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&temp->data);
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
            numberOfNodes++;
        }
        else if(insertChoice == 2)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&temp->data);
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            numberOfNodes++;
        }
        else if(insertChoice == 3)
        {
            int position;
            current = head;
            temp = (struct node*)malloc(sizeof(struct node));
            printf("Preview of list: ");
            while (current != NULL)
            {
                printf("%d " , current->data);
                current = current->next;
            }
            current = head;
            printf("\nAt what position do you want to insert: ");
            scanf("%d",&position);
            if(position <= numberOfNodes && position>0)
            {
                printf("Enter data: ");
                scanf("%d",&temp->data);
                temp->prev = NULL;
                temp->next = NULL;
                for(int i = 1 ; i < position ; i++)
                {
                    current = current->next;
                }
                if(current->prev != NULL)
                {
                    current->prev->next = temp;
                    temp->prev = current->prev;
                }
                else
                {
                    head = temp;
                    temp->prev = NULL;
                }
                current->prev = temp;
                temp->next = current;
                numberOfNodes++;
            }
            else
            {
                printf("Enter a valid position.\n");
            }
        }
        else if(insertChoice == 4)
        {
            break;
        }
        else
        {
            printf("Please input a valid number.\n");
        }
    }

    printf("List in normal order: ");
    current = head;
    while (current != NULL)
    {
        printf("%d " , current->data);
        current = current->next;
    }

    current = tail;
    printf("\nList in reversed order: ");
    while (current != NULL)
    {
        printf("%d " , current->data);
        current = current->prev;
    }

    current = head;
    while (current!=NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    current = NULL;
    temp = NULL;
    head = NULL;
    tail = NULL;
}
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp = NULL, *current = NULL;


int main()
{
    int i =0;
    char ch = 'Y';


    while (ch == 'y' || ch == 'Y')
    {
        i++;
        temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed.");
            return 1;
        }
        printf("Enter data: ");
        scanf("%d",&temp -> data);
        temp -> next = NULL;
        if (head  == NULL)
        {
            head = temp;
        }
        else
        {
            current -> next = temp;
        }
        current = temp;
        printf("Do you want to continue adding (y/n): ");
        scanf(" %c",&ch);
    }


    int choice;
    while (1)
    {
        printf("\n1 - Insert at beginning\n2 - Insert at end\n3 - Insert at a position\n4 - Delete a node\n5 - Print the final list\n");
        printf("\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            printf("\nEnter the value you want at starting: ");
            scanf("%d",&temp -> data);
            temp -> next = head;
            head = temp;
        }
        else if (choice == 2)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            printf("\nEnter the value you want to add at the end: ");
            scanf("%d",&temp -> data);
            temp -> next = NULL;
            current -> next = temp;
            current = temp;
        }
        else if (choice == 3)
        {
            int position;
            printf("\nPreview linked List: ");
            current = head;
            while (current != NULL)
            {
                printf("%d ",current->data);
                current = current->next;
            }
            printf("\nAt what position you want to add: ");
            scanf("%d",&position);
            printf("\n");
            if (position > 1 && position <= i)
            {
                temp = (struct node*)malloc(sizeof(struct node));
                printf("Enter the value you want to add: ");
                scanf("%d",&temp -> data);
                current = head;
                for (int i = 1 ; i <position-1 ; i++) current = current->next;
                temp->next = current->next;
                current->next = temp;
            }
            else
            {
                printf("Please enter a valid index.\n");
            }
        }
        else if (choice == 4)
        {
            printf("\n1 - Delete the beginning\n2 - Delete the end\n3 - Delete at intermediate\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                current = head;
                head = head->next;
                free(current);
                current = NULL;
            }
            else if(choice == 2)
            {
                current = head;
                for (int j = 1 ; j<i-1 ; j++)
                {
                    current = current->next;
                }
                free(current->next);
                current->next = NULL;
            }
            else if(choice == 3)
            {
                int position;
                printf("\nPreview linked List: ");
                current = head;
                while (current != NULL)
                {
                    printf("%d ",current->data);
                    current = current->next;
                }
                current = head;
                printf("\nEnter the position of the element you want to delete: ");
                scanf("%d",&position);
                for(int j = 1 ; j < position-1 ; j++)
                {
                    current = current->next;
                }
                temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Please enter a valid value.");
        }
    }


    printf("\nFinal linked List: ");
    current = head;
    while (current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    free(head);
    free(temp);
    free(current);
}
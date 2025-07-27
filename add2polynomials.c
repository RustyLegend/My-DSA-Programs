#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coefficient;
    int exponent;
    struct node* next;
}*head1 = NULL , *head2 = NULL , *ptr1 = NULL , *ptr2 = NULL , *temp = NULL , *head3 = NULL , *ptr3 = NULL;

struct node* newLinkedList(struct node* head , struct node* ptr , int NOT)
{
    while (NOT>0)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient: ");
        scanf("%d" , &temp->coefficient);
        temp->exponent = NOT-1;
        temp->next = NULL;
        if(head == NULL) head = temp;
        else ptr->next = temp;
        ptr = temp;
        NOT--;
    }
    return head;
}

int main()
{
    int numberOfTerms;
    printf("--------------- FIRST POLYNOMIAL ---------------\n");
    printf("Enter number of terms you want to enter: ");
    scanf("%d",&numberOfTerms);
    head1 = newLinkedList(head1 , ptr1 , numberOfTerms);

    printf("\n--------------- SECOND POLYNOMIAL ---------------\n");
    printf("Enter number of terms you want to enter: ");
    scanf("%d",&numberOfTerms);
    head2 = newLinkedList(head2 , ptr2 , numberOfTerms);
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        int sum;
        if(ptr1->exponent == ptr2->exponent)
        {
            sum = ptr1->coefficient + ptr2->coefficient;
            temp = (struct node*)malloc(sizeof(struct node));
            temp->coefficient = sum;
            temp->exponent = ptr1->exponent;
            temp->next = NULL;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exponent > ptr2->exponent)
        {
            sum = ptr1->coefficient;
            temp = (struct node*)malloc(sizeof(struct node));
            temp->coefficient = sum;
            temp->exponent = ptr1->exponent;
            temp->next = NULL;
            ptr1 = ptr1->next;
        }
        else
        {
            sum = ptr2->coefficient;
            temp = (struct node*)malloc(sizeof(struct node));
            temp->coefficient = sum;
            temp->exponent = ptr2->exponent;
            temp->next = NULL;
            ptr2 = ptr2->next;
        }
        if(head3 == NULL) head3 = temp;
        else ptr3->next = temp;
        ptr3 = temp;
    }

    //Printing
    printf("Polynomial 1 : ");
    ptr1 = head1;
    while (ptr1 != NULL)
    {
        if(ptr1->exponent != 0) printf("%dx^%d + " , ptr1->coefficient , ptr1->exponent);
        else printf("%d" , ptr1->coefficient);
        ptr1 = ptr1->next;
    }
    printf("\n");
    printf("Polynomial 2 : ");
    ptr2 = head2;
    while (ptr2 != NULL)
    {
        if(ptr2->exponent != 0) printf("%dx^%d + " , ptr2->coefficient , ptr2->exponent);
        else printf("%d" , ptr2->coefficient);
        ptr2 = ptr2->next;
    }
    printf("\n");
    printf("Sum: ");
    ptr3 = head3;
    while (ptr3 != NULL)
    {
        if(ptr3->exponent != 0) printf("%dx^%d + " , ptr3->coefficient , ptr3->exponent);
        else printf("%d",ptr3->coefficient);
        ptr3 = ptr3->next;
    }
    
}
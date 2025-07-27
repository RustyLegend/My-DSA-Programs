#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int exponent;
    float coefficient;
    struct node *next;
}*head1 = NULL , *head2 = NULL , *temp = NULL , *current1 = NULL , *current2 = NULL;

struct node newnode()
{
    temp = (struct node*)malloc(sizeof(struct node));

}
int main()
{
    char ch = 'Y';
    int terms_no1 = 0;
    int terms_no2 = 0;
    printf("---------FIRST POLYNOMIAL--------\n");
    while (ch == 'Y' || ch == 'y')
    {
        temp = (struct node*)malloc(sizeof(struct node));
        if(temp == NULL) printf("Memory allocation failed");
        printf("Enter coefficient: ");
        scanf("%f",&temp->coefficient);
        temp->next = NULL;
        if(head1 == NULL) head1 = temp;
        else current1->next = temp;
        terms_no1++;
        current1 = temp;
        printf("Do you wish to continue (y/n): ");
        scanf(" %c",&ch);
    }
    
    printf("\n---------SECOND POLYNOMIAL--------\n");
    ch = 'Y';
    while (ch == 'Y' || ch == 'y')
    {
        temp = (struct node*)malloc(sizeof(struct node));
        if(temp == NULL) printf("Memory allocation failed");
        printf("Enter coefficient: ");
        scanf("%f",&temp->coefficient);
        temp->next = NULL;
        if(head2 == NULL) head2 = temp;
        else current2->next = temp;
        terms_no2++;
        current2 = temp;
        printf("Do you wish to continue (y/n): ");
        scanf(" %c",&ch);
    }

    printf("1st polynomial:\n");
    current1 = head1;
    terms_no1--;
    while (current1!=NULL)
    {
        current1->exponent = terms_no1;
        printf("%.fx^%d",current1->coefficient,current1->exponent);
        current1 = current1->next;
        terms_no1--;
    }
    printf("\n");
    printf("2nd polynomial\n");
    current2 = head2;
    terms_no2--;
    while (current2!=NULL)
    {
        current2->exponent = terms_no2;
        printf("%.fx^%d",current2->coefficient,current2->exponent);
        current2 = current2->next;
        terms_no2--;
    }

    while (head1 != NULL && head2 !=NULL)
    {
        if(head1->exponent == head2->exponent)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            
        }
    }
}
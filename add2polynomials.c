#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
}*head1 = NULL , *head2 = NULL;

struct node *nodeCreator(struct node *head , int coeff , int expo)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> coeff = coeff;
    temp -> expo = expo;
    temp -> next = NULL;
    if (head == NULL) head = temp;
    else
    {
        struct node* current = head;
        while (current->next!=NULL) current = current->next;
        current->next = temp;
    }
    return head;
}

void displayNode(struct node* head)
{
    while (head!=NULL)
    {
        if(head->expo != 0) printf("%dx^%d + " , head->coeff , head->expo);
        else printf("%d" , head->coeff);
        head = head->next;
    }
    printf("\n");
}

struct node* addPolynomials(struct node* head1,struct node *head2)
{
    struct node* result = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if(head1->expo == head2->expo)
        {
            result = nodeCreator(result , head1->coeff + head2->coeff , head1->expo);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->expo > head2->expo)
        {
            result = nodeCreator(result , head1->coeff , head1->expo);
            head1 = head1->next;
        }
        else
        {
            result = nodeCreator(result , head2->coeff , head2->expo);
            head2 = head2->next;
        }
    }
    return result;
}

int main()
{
    int numberOfTerms;
    printf("---------FIRST POLYNOMIAL--------\n");
    printf("Enter number of terms: ");
    scanf("%d" , &numberOfTerms);
    while (numberOfTerms > 0)
    {
        int mainCoeff , mainExpo;
        printf("Enter coefficient and exponent respectively: ");
        scanf("%d %d",&mainCoeff,&mainExpo);
        head1 = nodeCreator(head1 , mainCoeff , mainExpo);
        numberOfTerms--;
    }

    printf("---------SECOND POLYNOMIAL--------\n");
    printf("Enter number of terms: ");
    scanf("%d",&numberOfTerms);
    while (numberOfTerms>0)
    {
        int mainCoeff , mainExpo;
        printf("Enter coefficient and exponent respectively: ");
        scanf("%d %d",&mainCoeff,&mainExpo);
        head2 = nodeCreator(head2 , mainCoeff , mainExpo);
        numberOfTerms--;
    }
    printf("Polynimial 1: ");
    displayNode(head1);
    printf("Polynomial 2: ");
    displayNode(head2);
    printf("Sum of the polynomials is: ");
    displayNode(addPolynomials(head1,head2));
}
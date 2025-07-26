#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct node
{
    int exponent;
    float coefficient;
    struct node* next;
}*head = NULL ,*current = NULL , *temp = NULL;


int main()
{
    int termsnumber = 0;
    char ch = 'Y';
    while (ch == 'Y' || ch == 'y')
    {
        termsnumber++;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient of the polynomial: ");
        scanf("%f",&temp->coefficient);
        temp -> next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            current -> next = temp;
        }
        current = temp;
        printf("Do you want to add more coefficients (y/n): ");
        scanf(" %c",&ch);
    }


    printf("Your polynomial is , f(x) : ");
    current = head;
    termsnumber--;
    while (current != NULL)
    {
        current -> exponent = termsnumber;
        if (current-> exponent!=0)
        {
            printf("%.1fx^%d + ",current->coefficient,current->exponent);
        }
        else
        {
            printf("%.1f\n",current->coefficient);
        }
        current  = current -> next;
        termsnumber--;
    }
    printf("Derivative of f(x) is: ");
    current = head;
    while (current!=NULL)
    {
        current -> coefficient *= current->exponent;
        current->exponent--;
        if (current-> exponent > 0)
        {
            printf("%.1fx^%d + ",current->coefficient,current->exponent);
        }
        else if (current->exponent == 0)
        {
            printf("%.1f\n",current->coefficient);
        }
        current  = current -> next;
    }
    current = head;
    while (current!=NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    current = NULL;
    head = NULL;
    temp = NULL;
}
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


    float x;
    float answer = 0;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    current = head;
    while (current != NULL)
    {
        answer = answer + (current->coefficient*(pow(x,current->exponent)));
        current = current->next;
    }
    printf("Value of f(%.1f) is %.2f",x,answer);


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
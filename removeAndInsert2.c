#include<stdio.h>


void Remover(int* a,int* size)
{
    int position;
    printf("Enter the position of the element you want to remove: ");
    scanf("%d",&position);
    if(position > 0 && position < (*size)+1)
    {
        position--;
        for (int i = position ; i < *size; i++)
        {
            *(a+i) = *(a+i+1);
        }
        (*size)--;
    }
    else
    {
        printf("Please enter correct position\n");
    }
}


void Inserter(int* a,int* size)
{
    int position;
    int insertNumber;
    printf("Enter the number you want to insert: ");
    scanf("%d",&insertNumber);
    printf("Enter the position of the element you want to insert: ");
    scanf("%d",&position);
    if(position>0 && position<(*size)+1)
    {
        position--;
        for (int i = *size; i > position; i--)
        {
            *(a+i) = *(a+i-1);
        }
        *(a+position) = insertNumber;
        (*size)++;
    }
    else
    {
        printf("Please enter correct position\n");
    }
}


int main()
{
    int size;
    char choice;
    printf("Enter how many number(s) you want to enter: ");
    scanf("%d",&size);
    int userArray[size+1];
    for (int i = 0; i < size; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&userArray[i]);
    }
    while (1)
    {
        printf("Enter 'i' for inserting and 'r' for removing an element 'q' to quit: ");
        scanf(" %c",&choice);
        if(choice == 'r')
        {
            Remover(userArray,&size);
        }
        else if(choice == 'i')
        {
            Inserter(userArray,&size);
        }
        else if(choice == 'q')
        {
            break;
        }
        else
        {
            printf("Please enter correct key.");
        }
        printf("After performing action the final array is:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\n",userArray[i]);
        }
    }
}
#include<stdio.h>
int main()
{
    int count;
    int even=0;
    int i =0;
    printf("Enter how many numbers: ");
    scanf("%d",&count);
    int array[count];
    while (i<count)
    {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
        i++;
    }
    i=0;
    while (i<count)
    {
        if(array[i]%2==0)
        {
            even++;
        }
        i++;
    }
    i=0;
    int j=0;
    int evenArray[even];
    while (i<count)
    {
        if(array[i]%2==0)
        {
            evenArray[j] = array[i];
            j++;
        }
        i++;
    }
    i=0;
    while (i<even)
    {
        printf("%d\n" ,evenArray[i]);
        i++;
    }
    printf("%d",even);
}
#include<stdio.h>
int main()
{
    int count;
    int max=0;
    int i =0;
    int min;
    printf("Enter how many elements you want to type: ");
    scanf("%d",&count);
    int arr[count];
    while (i<count)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
        i++;
    }
    i=0;
    while (i<count)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        i++;
    }
    i=0;
    min = max;
    while (i<count)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        i++;
    }
    printf("The maximum number is: %d\n",max);
    printf("The minimum number is %d",min);
}
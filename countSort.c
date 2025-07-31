#include<stdio.h>
int maximumNumberOfAnArray(int *a,int size)
{
    int max = *a;
    for(int i = 0 ; i < size ; i++)
    {
        if( *(a+i) > max)
        {
            max = *(a+i);
        }
    }
    return max;
}

int main()
{
    int numberOfElements;
    printf("Enter number of elements of the array: ");
    scanf("%d",&numberOfElements);
    int arr[numberOfElements];

    for(int i = 0 ; i<numberOfElements ; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    int max = maximumNumberOfAnArray(arr,numberOfElements);
    max++;
    int countArray[max];
    for (int i = 0 ; i < max ; i++) countArray[i] = 0;
    for (int i = 0 ; i < numberOfElements ; i++) countArray[arr[i]]++;
    
}
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

void countSort(int arr[] , int numberOfElements)
{
    int max = maximumNumberOfAnArray(arr,numberOfElements);
    max++;
    int count[max];
    for(int i = 0 ; i < max ; i++) count[i] = 0;
    for(int i = 0 ; i < numberOfElements ; i++) count[arr[i]]++;
    for(int i = 1 ; i < max ; i++) count[i] = count[i] + count[i-1];

    int sortedArray[numberOfElements];
    for(int i = numberOfElements-1 ; i>=0 ; i--)
    {
        sortedArray[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0 ; i < numberOfElements ; i++) arr[i] = sortedArray[i];
}

void readArray(int *arr , int numberOfElements)
{
    for(int i = 0 ; i < numberOfElements ; i++)
    {
        printf("Enter element %d: " , i+1);
        scanf("%d",(arr+i));
    }
}

void displayArray(int *arr , int numberOfElements)
{
    printf("The elements in a sorted manner is: ");
    for(int i = 0; i<numberOfElements ; i++) printf("%d ",arr[i]);
}

int main()
{
    int numberOfElements;
    printf("Enter number of elements of the array: ");
    scanf("%d",&numberOfElements);

    int arr[numberOfElements];

    readArray(arr,numberOfElements);

    countSort(arr,numberOfElements);

    displayArray(arr,numberOfElements);
}
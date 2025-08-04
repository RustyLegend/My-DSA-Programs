#include<stdio.h>
int maximumNumberOfAnArray(int *a,int size)
{
    int max = *a;
    for(int i = 1 ; i < size ; i++)
    {
        if( *(a+i) > max)
        {
            max = *(a+i);
        }
    }
    return max;
}

void countSort(int arr[] , int numberOfElements , int pv)
{
    int max = maximumNumberOfAnArray(arr,numberOfElements);
    max++;
    int count[10] = {0};
    for(int i = 0 ; i < numberOfElements ; i++) count[(arr[i]/pv) % 10]++;
    for(int i = 1 ; i < 10 ; i++) count[i] = count[i] + count[i-1];

    int sortedArray[numberOfElements];
    for(int i = numberOfElements-1 ; i>=0 ; i--)
    {
        sortedArray[count[(arr[i]/pv) % 10] - 1] = arr[i];
        count[(arr[i]/pv) % 10]--;
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

void radixSort(int *arr , int numberOfElements)
{
    int max = maximumNumberOfAnArray(arr,numberOfElements);
    for(int pv = 1 ; (max/pv) > 0 ; pv *= 10)
    {
        countSort(arr,numberOfElements,pv);
    }
}

int main()
{
    int numberOfElements;
    printf("Enter number of elements: ");
    scanf("%d",&numberOfElements);
    int arr[numberOfElements];
    readArray(arr,numberOfElements);
    radixSort(arr,numberOfElements);
    displayArray(arr,numberOfElements);
}
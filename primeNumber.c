#include<stdio.h>
int main()
{
    int N;
    int sum;
    int primeSum=0;
    printf("Enter a number: ");
    scanf("%d",&N);
    for (int i = 1; i <= N; i++)
    {
        sum=0;
        for (int j = 0; j < i; j++)
        {
            if(i%(j+1)==0)
            {
                sum = sum + (j+1);
            }
        }
        if(sum == (i+1))
        {
            primeSum += i;
        }
    }
    printf("The sum of all primes until %d is: %d", N , primeSum);
}
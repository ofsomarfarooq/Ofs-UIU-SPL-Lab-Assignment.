#include<stdio.h>
int sum_digit(int k)
{
    int sum = 0;
    while(k > 0)
    {
        sum += k % 10;
        k /=10;
    }
    return sum;
}
int main()
{
    int num[100];
    int n;
    printf("How many numbers:");
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&num[i]);
    }

    int digit_total = 0;
    int num_total = 0;
    printf("\n");
    for(int i = 0;i<n;i++)
    {
        int digit_sum = sum_digit(num[i]);
        printf("%d : %d\n",num[i],digit_sum);
        digit_total += digit_sum;
        num_total += num[i];
    }

    printf("Total sum of digits: %d\n", digit_total);
    printf("Total sum of numbers: %d\n",num_total);
    printf("\n");
    if(digit_total > num_total)
    {
        printf("Sum of digits > Sum of numbers \n");
    }
    else if(digit_total < num_total)
    {
        printf("Sum of numbers > Sum of digit");
    }
    else
    {
        printf("Sum of digits = Sum of numbers");
    }

    return 0;
}

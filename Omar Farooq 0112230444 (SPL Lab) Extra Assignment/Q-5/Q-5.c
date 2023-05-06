#include<stdio.h>

void sign_add(char str[])
{
    int n = strlen(str);

    for(int i = 0;i<= (n/2); i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("$");
        }
        if(i != n/2)
        printf("%c",str[i]);
    }

    for(int i = n/2; i < n; i++)
    {
        printf("%c",str[i]);
        for(int j = i;j < n; j++)
        {
            printf("$");
        }
    }


}

int palindrome_check(char str[],int start, int end)
{
    if(start >= end)
    {
        return 1;
    }

    if(str[start] != str[end])
    {
        return 0;
    }
    return palindrome_check(str, start+1,end-1);
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0' ;
    int len = strlen(str);
    if(palindrome_check(str,0,len-1))
    {
        printf("Palindrome.\n");
        sign_add(str);
    }
    else
    {
        printf("Not Palindrome.\n");
    }
}

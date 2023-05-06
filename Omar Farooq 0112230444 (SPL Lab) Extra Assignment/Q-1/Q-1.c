#include<stdio.h>


int consonant_count(char w[])
{
    int count = 0;

     for(int i =0 ; i < strlen(w); i++)
     {

        int c = tolower(w[i]);
     if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        count++;

     }
     return count;
}

int vowel_count(char w[])
{

     int count = 0;

     for(int i =0; i < strlen(w); i++)
     {
        char c = tolower(w[i]);
     if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        count++;

     }
     return count;
}

int main()
{
    char words[100][50];
    int n;
    printf("How many words:");
    scanf("%d",&n);
    for(int i=0; i<n;i++)
    {
        fflush(stdin);
        gets(words[i]);
    }
    int long_lenght = 0;
    char long_word[100] = "" ;
    int flag = 0;

    for(int i=0;i<n;i++)
    {
        int con = consonant_count(words[i]) ;
        int vow = vowel_count(words[i]) ;

        if(con >= 3 && vow >= 3 && strlen(words[i]) > long_lenght)
        {
            strcpy(long_word, words[i]);
            long_lenght = strlen(words[i]);
            flag = 1;
        }
    }

        if(flag == 1)
        printf("The longest word is %s\n", long_word);
        else
        printf("Nothing Found like 3 consonant and 3 vowel\n");

    return 0;

}

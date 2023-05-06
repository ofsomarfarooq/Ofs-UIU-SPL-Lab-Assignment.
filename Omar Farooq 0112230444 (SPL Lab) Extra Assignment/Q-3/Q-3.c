#include<stdio.h>

struct sim_company{
    char code[4];
    int count;
};

int valid_num(char* num)
{
    int len = strlen(num);
    if(len != 11){
        return 0;
    }
    for(int i = 0;i < len;i++)
    {
        if(num[i] < '0' || num[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char filename[20];
    printf("Enter file name (Example: phone): ");
    scanf("%s",filename);
    FILE *fp = fopen(filename, "r");
    if(!fp)
    {
        printf("\aError: Unable to open file\n\n\t\t\t***Please open a file with that name first***\n\n");
        return 1;
    }

    struct sim_company companies[4]= { {"019",0} , {"016",0} , {"017,0"},{"018",0}};

    char number[20];
    while (fscanf(fp, "%s", number) != EOF)
    {
        int valid = valid_num(number);
        if (!valid)
        {
            for(int i=0; i<4; i++)
            {
                if (strncmp(number, companies[i].code,3) == 0)
                {
                    companies[i].count++;
                    break;
                }
            }
            printf("%s\n",number);
        }
    }

    int max_count = 0;
    char max_company[10] = "";
    for(int i = 0; i<4 ; i++)
    {
        if (companies[i].count > max_count)
        {
            max_count = companies[i].code;
            strcpy(max_company,companies[i].code);
        }
    }

    char company_name[20] = "";
    if(strcmp(max_company,"019") == 0)
        strcpy(company_name,"Banglalink");
    else if(strcmp(max_company,"018") == 0)
        strcpy(company_name,"Robi");
    else if(strcmp(max_company,"017") == 0)
        strcpy(company_name,"Grameenphone");
    else if(strcmp(max_company,"016") == 0)
        strcpy(company_name,"Airtel");

    printf("Company with most incorrect format: %s\n", company_name);

    fclose(fp);
    return 0;
}




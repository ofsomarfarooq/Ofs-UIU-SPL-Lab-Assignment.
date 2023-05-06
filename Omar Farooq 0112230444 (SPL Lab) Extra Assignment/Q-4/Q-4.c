#include<stdio.h>

struct car{
    char make[20];
    char model[20];
    int year;
    float price;
};


int read_cars(struct car cars[],char filename[])
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error opening file.\n\n\t\t You have to Creat A cars.txt file first\n\t\t\t***Reamember File name: \"cars.txt\"\n\n");
    }
    int i = 0;
    while(fscanf(fp, "%s %s %d %f", cars[i].make,cars[i].model, &cars[i].year, &cars[i].price) != EOF) {
        i++;
        if (i >= 100){
            break;
        }
    }
    fclose(fp);
    return i;
}

void search_cars(struct car cars[], int n, char make[], char model[]) {
    int i;
    printf("Search results:\n");
    for(i = 0;i <n; i++){
        if ((strlen(make) == 0 || strcmp(cars[i].make, make) == 0) && (strlen(model) == 0 || strcmp(cars[i].model, model )==0)) {
            printf("%s %s %d $%.2f\n", cars[i].make,cars[i].model, cars[i].year, cars[i].price);
        }
    }
}

void sort_cars_by_year(struct car cars[],int n){
    int i,j;
    struct car temp;
    for(i = 0; i<n-1;i++){
        for(j= 0;j< n-i-1;j++){
            if(cars[j].year > cars[j+1].year){
                temp = cars[j];
                cars[j] =cars[j+1];
                cars[j+1] = temp;
            }
        }
    }

}

void sort_cars_by_price(struct car cars[], int n){
    int i,j;
    struct car temp;
    for(i=0; i<n-1;i++){
        for(j=0; j<n-i-1; j++){
            if (cars[j].price > cars[j+1].price) {
                temp = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = temp;
            }
        }
    }
}

int main()
{
    int choice;
    struct car cars[100];
    int n = read_cars(cars, "cars.txt");
    char make[20],model[20], sort_by;
    printf("1. See car details.\n");
    printf("2. See all cars by sorting by Year or Price.\n");
    printf("Enter Your Coice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter Make & Model to search for, Example: (Honda Civic) :\n");
        scanf("%s %s",make, model);
        search_cars(cars, n, make, model);
    case 2:
        printf("Sort by year or price? (y/p)\n");
        scanf(" %c",&sort_by);
        if(sort_by == 'y'){
            sort_cars_by_year(cars,n);
        }
        else if(sort_by == 'p')
        {
            sort_cars_by_price(cars,n);
        }
        printf("Sorted results:\n");
        for(int i = 0; i< n; i++)
        {
            printf("%s %s %d $%.f\n",cars[i].make, cars[i].model, cars[i].year, cars[i].price);
        }
    default:
        printf("Wrong Press");
    }
    return 0;
}




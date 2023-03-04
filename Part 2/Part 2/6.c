#include<stdio.h>
#include<stdlib.h>

struct data
{
    char name[100];
    int roll;
    int marks[100];
    char subject[100][100];
};

int main()
{
    struct data *ptr;
    int n, i, n1, j;

    printf("Enter the number of whom you want to store information: \n");
    scanf("%d", &n);
    printf("Enter the number of subject for which you want to enter marks: \n");
    scanf("%d", &n1);

    ptr = (struct data*) malloc(n * sizeof(struct data));

    for (i=0; i<n; i++)
    {
        printf("Enter the Name of student %d: \n", i+1);
        scanf("%s", &(ptr+i)->name);
        printf("Enter the Roll number of student %d: \n", i+1);
        scanf("%d", &(ptr+i)->roll);
        
        for (j=0; j<n1; j++)
        {
            printf("Enter the Name of subject %d: ", j+1);
            scanf("%s", &(ptr+i)->subject[j]);
            printf("Enter the Mark for subject %d: ", j+1);
            scanf("%d", &(ptr+i)->marks[j]);
        }
    }

    printf("\n\nThe entered information: \n");
    for (i=0; i<n; i++)
    {
        printf("\n\nInformation for Student %d\n", i+1);
        printf("The Name of student %d: ", i+1);
        printf("%s\n", (ptr+i)->name);
        printf("The Roll number of student %d: ", i+1);
        printf("%d\n", (ptr+i)->roll);

        for (j=0; j<n1; j++)
        {
            printf("The Name of subject %d: ", j+1);
            printf("%s\n", (ptr+i)->subject[j]);
            printf("The Mark for subject %d: ", j+1);
            printf("%d\n", (ptr+i)->marks[j]);
        }
    }

    free(ptr);

    return 0;
}
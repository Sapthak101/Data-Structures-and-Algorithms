#include<stdio.h>
#include<string.h>

struct data
{
    char name[100];
    int roll_no;
    int marks[100];
    char sub[100][100];
};

int main()
{
    struct data st_details[100];
    int i, j, n1, n2;

    printf("Enter the number of student for whom you want to enter the data: \n");
    scanf("%d", &n1);
    printf("Enter the number of subject for which you want the marks: \n");
    scanf("%d", &n2);

 printf("Enter the data of the students: \n");
 for (i=0; i<n1; i++)
 {
    printf("Enter name: \n");
    scanf("%s", st_details[i].name);  

    printf("Enter Roll No.: \n");
    scanf("%d", &st_details[i].roll_no);

    for (j=0; j<n2; j++)
    {
        printf("Enter the subject name: \n");
        scanf("%s", st_details[i].sub[j]);

        printf("Enter the obtained number: \n");
        scanf("%d", &st_details[i].marks[j]);
    }  
 }
 
  printf("\n\nThe entered data of the students: \n\n");
    for (i=0; i<n1; i++)
    {
        printf("Name: %s\n", st_details[i].name);
        printf("Roll No.: %d\n", st_details[i].roll_no);

            for (j=0; j<n2; j++)
            {
                printf("\tThe subject name: %s", st_details[i].sub[j]);
                printf("\tEnter the obtained number: %d\n", st_details[i].marks[j]);
            }  
    }
                        
 return 0;
}
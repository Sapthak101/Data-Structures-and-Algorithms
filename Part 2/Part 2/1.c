#include<stdio.h>
#include<stdlib.h>

struct data
{
    char name[100], desig[100], gender, department[100]; 
    float basic_pay, gross_pay;
};
int main()
{
 struct data *ptr;
 int n, i;

 printf("Enter the number of record files you want to open: \n");
 scanf("%d", &n);

 ptr = (struct data*) malloc(n * sizeof(struct data));
 
    for (i=0; i<n; i++)
    {
        printf("Enter the name, designition, gender, department, Basic pay of employee $ %d: \n", i+1);
        scanf("%s %s %c %s %f", (ptr+i)->name, (ptr+i)->desig, &(ptr+i)->gender, 
                                    (ptr+i)->department, &(ptr+i)->basic_pay);
    
        (ptr+i)->gross_pay=(0.25*(ptr+i)->basic_pay)+(ptr+i)->basic_pay+
        (0.75*(ptr+i)->basic_pay) ;
    }

    for (i=0; i<n; i++)
    {
    
        printf("\nName: %s, Designition: %s, Gender: %c, Department %s, Gross Pay $: %.2f\n", 
        (ptr+i)->name, (ptr+i)->desig, 
        (ptr+i)->gender, (ptr+i)->department, (ptr+i)->gross_pay);
    }

return 0;
}
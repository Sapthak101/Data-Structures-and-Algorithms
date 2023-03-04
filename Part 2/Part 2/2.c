#include<stdio.h>

struct data
{
    int dist, dist1;
};
int main()
{
    struct data d1, d2;
    int km,m;
    
    printf("Enter distance one \n");
    printf("Enter the distance in km \n");
    scanf("%d", &d1.dist);

    printf("Enter the distance in meter\n");
    scanf("%d", &d1.dist1);

    printf("Enter distance two\n");
    printf("Enter the distance in km \n");
    scanf("%d", &d2.dist);

    printf("Enter the distance in meter\n");
    scanf("%d", &d2.dist1);
    
    km=d1.dist+d2.dist;
    m=d1.dist1+d2.dist1;

    while(m>=1000)
    {
        m=m-1000;
        km++;
    }
    printf("The total distance is: %d km and %d meters\n", km, m);

    return 0;
}
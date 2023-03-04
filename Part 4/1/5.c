#include<stdio.h>  
#include<stdlib.h>

struct node{  
    double data;  
    struct node *next;  
};      
    
struct node *head, *tail = NULL;  
     
void task1(double data) {   
    struct node *cur;

    cur= (struct node*)malloc(sizeof(struct node));  
    cur->data = data;  
    cur->next = NULL;  
      
    if(head == NULL) {  
        head = cur;  
        tail = cur;  
    }  
    else {  
        tail->next = cur;  
        tail = cur;  
    }  
}

void task2() {  
    struct node *current = head, *index = NULL; 
    double temp;  
      
    if(head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL){  
            index = current->next;  
              
            while(index != NULL) {  
                if(current->data > index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;   
                }   
                index = index->next;  
            }  
            current = current->next;  
        }          
    }  
}  
    
void task3() {  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {  
        printf("Data= %.2lf | Address= %u | Next Address= %u \n", 
                            current->data, current, current->next);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    int i, n;
    double val;

    printf("Enter the number of nodes you want to add: \n");
    scanf("%d", &n);
    for (i=0 ;i<n; i++){
        printf("Enter the data for node %d: ", i+1);
        scanf("%lf", &val);
        task1(val);
        val=0;
    }
      
    printf("The original list: \n");  
    task3();  
      
    task2();  
      
    printf("List after sorting: \n");  
    task3();  

    printf("Enter a new element: \n");
    scanf("%lf", &val);
    task1(val);
    task2();

    printf("After sorting: \n");
    task3();    
          
    return 0;  
}  
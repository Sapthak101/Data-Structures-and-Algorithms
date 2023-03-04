#include<stdio.h>  
#include<stdbool.h>  
#include<stdlib.h> 

struct node{  
    double data;  
    struct node *next;  
} *head= NULL, *tail = NULL;  

int size = 0;  
     
void task1(int data) {  
    struct node *cur;

    cur = (struct node*)malloc(sizeof(struct node));  
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
    size++;  
}  
   
struct node* task3_revList(struct node *temp){  
    struct node *current; 
    current= temp;  
    struct node *prevNode, *nextNode;
     
    prevNode=nextNode = NULL;  
      
    while(current != NULL){  
        nextNode = current->next;  
        current->next = prevNode;  
        prevNode = current;  
        current = nextNode;  
    }                                                                                    
    return prevNode;  
}  
                                
void task2_Pallin(){  
    struct node *current;
    bool flag;
    int mid, i;

    current = head;
    flag = true;  

    mid = (size%2 == 0)? (size/2) : ((size+1)/2);  
      
    for(i=1; i<mid; i++){  
        current = current->next;  
    }  
      
    struct node *revHead = task3_revList(current->next);  
    
    while(head != NULL && revHead != NULL){  
        if(head->data != revHead->data){  
            flag = false;  
            break;  
        }  
        head = head->next;  
        revHead = revHead->next;  
    }  
   
    if(flag)  
        printf("The linked list is palindrome\n");  
    else  
        printf("The linked list is not palindrome\n");  
}  
      
void task4() {  
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
        printf("Enter the data node %d: ", i+1);
        scanf("%lf", &val);
        task1(val);
        val=0;
    }

    task4();  
    
    task2_Pallin();  
      
    return 0;  
}  
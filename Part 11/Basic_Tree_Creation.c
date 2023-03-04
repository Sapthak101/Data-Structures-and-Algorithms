#include<stdio.h>   
#include<stdlib.h>
#define MAX 10000
   
struct node
{
    int data;
    struct node *left, *right;
};

struct node *root=NULL;

struct stack
{
    struct node *data[MAX];
    int top, top1;
};


struct stack s1;
int count=0;


struct node* create_node(int data);
void inorder(struct node *r);
void postorder(struct node *r);
void preorder(struct node *r);
void level_wise(struct node *r);
void display_level();
void push(struct node *r);
void search(struct node *r, int data, struct node **ptr);
int height(struct node *r);
int max(int a, int b);
void depth(struct node *r, int data, int *ptr);
void level_wise_printing(struct node *r, int data);


int main()
{
    s1.data[MAX]=NULL;
    s1.top=-1;
    s1.top1=0;
    int num, num1, num2;
    struct node *ptr;

    //Node Creation
    printf("Enter the data for the root: ");
    scanf("%d", &num);
    root=create_node(num);

    printf("Enter the data for the root: ");
    scanf("%d %d", &num, &num1);
    root->left=create_node(num);
    root->right=create_node(num1);
    
    printf("Enter the data for the root: ");
    scanf("%d", &num);
    root->right->left=create_node(num);

    //Traversal
    printf("\n");
    printf("Inorder Traversal: \n");
    inorder(root);
    printf("\n");
    printf("Preorder Traversal: \n");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal: \n");
    postorder(root);
    printf("\n");

    printf("\nLevel-wise traversal: \n");
    push(root);
    level_wise(root);
    display_level();

    //Search
    printf("\nEnter an element to search: \n");
    scanf("%d", &num);
    search(root, num, &ptr);

    //Height
    printf("\nThe height of the tree: %d\n", height(root)+1); //to calculate the height of any node we need to just pass the address of that node
    printf("\nEnter the node data to calculate the depth: \n");
    scanf("%d", &num);

    //Depth
    depth(root, num, &num2);
    printf("\nThe depth of the expected node is: %d", num2);

    //level_wise printing
    printf("\nEnter the level: \n");
    scanf("%d", &num);
    level_wise_printing(root, num);

    return 0;
}


struct node* create_node(int data)
{
    struct node *cur=(struct node*)malloc(sizeof(struct node));
    cur->data=data;
    cur->left=cur->right=NULL;

    return cur;
}
void inorder(struct node *r)
{
    if (r!=NULL)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}
void preorder(struct node *r)
{
    if (r!=NULL)
    {
        printf("%d ", r->data);
        inorder(r->left);
        inorder(r->right);
    } 
}
void postorder(struct node *r)
{
    if (r!=NULL)
    {
        inorder(r->left);
        inorder(r->right);
        printf("%d ", r->data);
    } 
}
void level_wise(struct node *r)
{
    if (r==NULL)
        return;
    s1.top1++;
    if (r!=NULL)
    {
        if (r->left!=NULL)
            push(r->left);
        if (r->right!=NULL)
            push(r->right);
        level_wise(s1.data[s1.top1]);
    }
}
void display_level()
{
    for (int i=0; i<s1.top1; i++)
        printf("%d ", s1.data[i]->data);
}
void push(struct node *r)
{
    if (s1.top==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    s1.top++;
    s1.data[s1.top]=r;
}
void search(struct node *r, int data, struct node **ptr)
{
    if (r!=NULL)
    {
        search(r->left, data, ptr);
        if (r->data==data)
        {
            printf("Data Found\n");
            *ptr=r;
        }
        search(r->right, data, ptr);
    }
}
int height(struct node *r)
{
    if (r==NULL)
        return -1;
    
    return max(height(r->left), height(r->right))+1;
}
int max(int a, int b)
{
    if (a>b)
        return a;
    else if (b>a)
        return b;
    else
        return a;
}
void depth(struct node *r, int data, int *ptr)
{
    if (r!=NULL)
    {
        if  (r->data==data)
        {
            *ptr=count;
        }
        count++;
        depth(r->left, data, ptr);
        depth(r->right, data, ptr);
        count--;
    }
}
void level_wise_printing(struct node *r, int data)
{
    if (r!=NULL)
    {
        if  (data==count)
        {
            printf("%d ", r->data);
        }
        count++;
        level_wise_printing(r->left, data);
        level_wise_printing(r->right, data);
        count--;
    }
}
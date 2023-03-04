#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root=NULL;

struct node * insert(struct node *r, int val);
void inorder(struct node *r);
void postorder(struct node *r);
void preorder(struct node *r);
void search(struct node *r, int val);
struct node * find_max(struct  node *r);
struct node * find_min(struct  node *r);
struct node * delete(struct  node *r, int val);

int main()
{
    int choice,choice1, data, num;
    do
    {
        printf("............Binary Search Tree Operation...........\n");
        printf("0. Quit\n");
        printf("1. Create\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Search\n");
        printf("6. Find Smallest Element\n");
        printf("7. Find Largest Element\n");
        printf("8. Deletion of a tree\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
            {
                return 0;
                break;
            }
            case 1:
            {
                printf("Enter the node data: ");
                scanf("%d", &data);
                root=insert(root, data);
                break;
            }
            case 2:
            {
                inorder(root);
                break;
            }
            case 3:
            {
                preorder(root);
                break;                
            }
            case 4:
            {
                postorder(root);
                break;                
            }
            case 5:
            {
                printf("Enter the data you want to search: \n");
                scanf("%d", &num);
                search(root, num);
                break;                
            }
            case 6:
            {   
                printf("%d ", find_min(root)->data);
                break;                
            }
            case 7:
            {
                printf("%d ", find_max(root)->data);
                break;
            }
            case 8:
            {
                printf("Enter the node value to delete: \n");
                scanf("%d", &num);
                delete(root, num);
                break;
            }
        }
        printf("\nDo you want to continue further (Y/N):\n");
        scanf("%s", &choice1);
    }while (choice1=='Y');

    return 0;
}

struct node * insert(struct node *r, int val)
{
    if (r==NULL)
    {
        struct node *cur=(struct node *)malloc(sizeof(struct node));
        cur->left=cur->right=NULL;
        cur->data=val;
        
        return cur;
    }
    else if (val>r->data)
    {
        r->right=insert(r->right, val);
        return r;
    }
    else if (val<r->data)
    {
        r->left=insert(r->left, val);
        return r;
    }
    else
        return r;
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
void search(struct node *r, int val)
{
    if (r!=NULL)
    {
    if (val>r->data)
        search(r->right, val);
    else if (val<r->data)
        search(r->left, val);
    else
        printf("Data found\n");
    }
}
struct node * find_max(struct  node *r)
{
    if (r==NULL)
        return r;
    else if (r->right==NULL)
        return r;
    return find_max(r->right);
}
struct node * find_min(struct  node *r)
{
    if (r==NULL)
        return r;
    else if (r->left==NULL)
        return r;
    return find_min(r->left);
}
struct node * delete(struct  node *r, int val)
{
    if (r==NULL)
        return r;
    else if (val>r->data)
    {
        r->right=delete(r->right, val);
        return r;
    }
    else if (val<r->data)
    {
        r->left=delete(r->left, val);
        return r;
    }
    else
    {
        if (r->left!=NULL && r->right!=NULL)
        {
            struct node *cur=find_max(r->left);
            r->data=cur->data;
            r->left=delete(r->left, r->data);
            return r;
        }
        else if (r->right!=NULL)
        {
            struct node *temp=r->right;
            free(r);
            return temp;
        }
        else if (r->left!=NULL)
        {
            struct node *temp=r->left;
            free(r);
            return temp;
        }
        else
        {
            free(r);
            return NULL;
        }
    }
}
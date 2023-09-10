/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 06.09.2023
Desription: Linked List Functions
*/

#include<stdio.h>
#include<stdlib.h>
//stdlib for malloc and free

//global variables
int choice, x, p;

//strcture of a node of LL
struct node
{
    struct node *next;
    int info;
};

//to create memory for a node
struct node* getnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
}

//to free a node
void freenode(struct node* p)
{
    free(p);
}

//initializing the LL
struct node *list = NULL;

//to insert an element in beggining of LL
void insertBeg(int x)
{
    struct node *newnode;
    newnode=getnode();
    newnode->info=x;
    newnode->next=list;
    list=newnode;
}

//to insert an element at p point in LL
void insertAtP(int p, int x)
{
    if(list==NULL||p==1)
    {
        //if empty or insert at beg
        insertBeg(x);
        return;
    }
    struct node *nn, *temp;
    nn=getnode();
    nn->info=x;
    temp=list;

    for(int i=1; i<p-1; i++)
    {
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next=nn;
}

//to insert an element at end of LL
void insertEnd(int x)
{
    if(list==NULL)
    {
        //if empty
        insertBeg(x);
        return;
    }
    struct node *nn, *temp;
    nn= getnode();
    nn->info = x;
    nn->next =NULL;
    temp = list;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next = nn;
}

//to delete first node
void deleteBeg()
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    struct node *temp;
    temp =list;
    list = list->next;
    freenode(temp);
}

//to delete pth node
void deleteAtP(int p)
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    if(p==1)
    {
        deleteBeg();
        return;
    }
    struct node *temp, *t2;
    temp =list;
    for(int i=1; i<p; i++)
    {
        t2 = temp;
        temp= temp->next;
    }
    t2->next=t2->next->next;
    freenode(temp);
}

//to delete last node
void deleteEnd()
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    if(list->next==NULL)
    {
        deleteBeg();
        return;
    }
    struct node *temp, *t2;
    temp=list;
    while(temp->next->next!=NULL)
    {
        t2=temp;
        temp =temp->next;
    }
    freenode(temp->next);
    temp->next=NULL;
}

//to display LL
void display()
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    struct node *temp;
    temp=list;
    while(temp->next!=NULL)
    {
        printf("%d\n", temp->info);
        temp=temp->next;
    }
    printf("%d", temp->info);
}

void main()
{

    /*calling the everlasting choices*/
    while(choice!=8)
    {
        /*description of menu bar*/
        printf("\n\n\n\n-----These are the menu panel-----");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at pth position");
        printf("\n3. Insert at end");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from pth position");
        printf("\n6. Delete from end");
        printf("\n7. Traverse");
        printf("\n8. Exit");
        printf("\nenter the option no.: ");
        scanf("%d", &choice);

        /*switch on entered choice*/
        switch(choice)
        {
            /*case-wise calling functions*/
            case 1: 
                printf("enter the number to be added in LL: ");
                scanf("%d", &x);
                insertBeg(x);
                break;
            case 2: 
                printf("enter the number to be added in LL: ");
                scanf("%d", &x);
                printf("enter the position at which to be added in LL: ");
                scanf("%d", &p);
                insertAtP(p, x);
                break;
            case 3: 
                printf("enter the number to be added in LL: ");
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 4: 
                deleteBeg();
                break;
            case 5: 
                printf("enter the position at which to be deleted in LL: ");
                scanf("%d", &p);
                deleteAtP(p);
                break;
            case 6: 
                deleteEnd();
                break;
            case 7: 
                display();
                break;
            case 8:
                break;
            default:
                printf("incorrect choice");
        }
    }/*end of while*/

    /*code execution completed*/
    printf("You got exit\n\n");
}
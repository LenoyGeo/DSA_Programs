/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 06.09.2023
Desription: Array Implementation of Double Ended Queue
*/
#include<stdio.h>
#include<stdlib.h>
#define n 10
void enqfront(int x);
void enqrear(int x);
void deqfront();
void deqrear();
void display();
int f=-1;
int r=-1;
int queue[n];
void main(){
    int ch,x;
    while(1){
        printf("\n----Queue Operations----\n");
        printf("1. Enqueue Element From Front\n");
        printf("2. Enqueue Element From Rear\n");
        printf("3. Dequeue Element From Front\n");
        printf("4. Dequeue Element From Rear\n");
        printf("5. Display Elements\n");
        printf("6. Exit\n");
    printf("Enter Number:\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("\nEnter Element to be Inserted: ");
            scanf("%d",&x);
            enqfront(x);
            break;
        case 2:
            printf("\nEnter Element to be Inserted: ");
            scanf("%d",&x);
            enqrear(x);
            break;
        case 3:
            deqfront();
            break;
        case 4:
            deqrear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Invalid Number.\n");
        }
    }
}
void enqfront(int x){
    if((f==0 && r==n-1)||(f==r+1)){
        printf("Queue is Full.\n");
    }
    else{
        if(f==0){
            f=n-1;
            queue[f]=x;
            printf("Element %d has been inserted.\n",x);
        }
        else{
            f--;
            queue[f]=x;
            printf("Element %d has been inserted.\n",x);
        }
    }
}
void enqrear(int x){
    if((f==0 && r==n-1) || f==r+1){
        printf("Queue is Full.\n");
    }
    else{
        if(f==-1 && r== -1){
            f++;
            r++;
            queue[r]=x;
            printf("Element %d has been inserted.\n",x);
        }
        else{
            r=(r+1)%n;
            queue[r]=x;
            printf("Element %d has been inserted.\n",x);
        }
    }
}
void deqfront(){
    if(f==-1 && r== -1){
        printf("Queue is Empty.");
    }
    else{
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%n;
            printf("Element has been deleted.\n");
        }
    }
}
void deqrear(){
    if(f==-1 && r== -1){
        printf("Queue is Empty.");
    }
    else{
        if(r==0){
            r=n-1;
        }
        else{
            r--;
        }
    }
}
void display(){
    if(f==-1 && r== -1){
        printf("Queue is Empty.");
    }
    else{
        printf("Elements are:\n");
        for(int i=f;i<=r;i++){
            printf("%d\n",queue[i]);
        }
    }
}

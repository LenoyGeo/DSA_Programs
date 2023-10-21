/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 22.09.2023
Desription: Quick Sort
*/
#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[], int first, int last);
void main(){
    int a[20],n,i;
    printf("Enter total number of elements:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nBefore Sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nAfter Sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void quicksort(int a[],int first,int last){
    int pivot,j,temp,i;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(a[i]<=a[pivot]&&i<last)
            i++;
            while(a[j]>a[pivot])
            j--;
            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}
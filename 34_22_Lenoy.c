/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 22.09.2023
Desription: Insertion Sort
*/
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
void main(){
    int i,j,n,temp,a[20];
    //clrscr();
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
    insertionsort(a,n);
    printf("\nAfter Sorting:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }    
}
insertionsort(int a[], int n){
    int i,j,k,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while((temp<a[j])&&(j>=0)){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
        printf("\nPass %d:",i);
        for(k=0;k<n;k++)
            printf("%d ",a[k]);
    }

}
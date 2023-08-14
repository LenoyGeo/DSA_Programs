//To find largest element in array
#include<stdio.h>
void main(){
    int a[10],i,n,t;
    printf("Enter Number of Elements in Array:");
    scanf("%d",&n);
    printf("\nEnter Array Elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int largest=0;
    for(i=0;i<n;i++){
        if(a[i]>largest){
          largest=a[i];
        }
    }
    printf("\nLargest Element in Array is: %d",largest);
}
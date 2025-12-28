#include<stdio.h>
void main(){
    int a[]={50,60,40,70,20,10,100,30,80,90},i,min;
    min=a[0];
    for(i=1;i<10;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("Minimum element in the array is: %d\n",min);
}
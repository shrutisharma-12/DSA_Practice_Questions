#include <stdio.h>
void main(){
    int a[]={50,60,40,70,20,10,100,30,80,90},i,n,f=0;
    printf("Enter element to search: ");
    scanf("%d",&n);
    for(i=0;i<10;i++){
        if(a[i]==n){
            f=1;
            break;
        }
    }
    if(f==1){
        printf("Element found");
    }
    else{
        printf("Element not found");
    }
}
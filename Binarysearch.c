#include <stdio.h>
void main(){
    int a[]={10,20,30,40,50,60,70,80,90,100};
    int n,low=0,high=9,mid,f=0;
   printf("Enter element to search: ");
   scanf("%d",&n);
   while(low<=high){
       mid=(low+high)/2;
       if(a[mid]==n){
           f=1;
           break;
       }
       else if(n>a[mid]){
           low=mid+1;
       }
         else{
              high=mid-1;
         }
   }
   if(f==1){
       printf("Element found");
   }
   else{
       printf("Element not found");
   }
}
#include <stdio.h>
void main(){
    int n,r;
    printf("Enter a number to reverse: ");
    scanf("%d",&n);
    printf("Reversed number: ");
    while(n!=0){
        r=n%10;
        printf("%d",r);
        n=n/10;
    }   
}
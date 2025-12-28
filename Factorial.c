#include <stdio.h>
void main(){
    int n,fact=1,i;
    printf("Enter a number to find its factorial: ");
    scanf("%d",&n);
    while(n>1){
        fact=fact*n;
        n--;
    }
    printf("Factorial is: %d\n",fact);
}
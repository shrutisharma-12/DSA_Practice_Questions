#include <stdio.h>
void main(){
    int a=0,b=1,c,n=7,i=1;
    printf("%d\n%d\n",a,b);
    while(i<=n-2){
        c=a+b;
        printf("%d\n",c);
        a=b;
        b=c;
        i++;
    }
    printf("Fibonacci series up to %d terms printed.\n", n);
}
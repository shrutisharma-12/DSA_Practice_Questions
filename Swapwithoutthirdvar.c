#include <stdio.h>
void main(){
    int a, b;
    printf("Enter First number: ");
    scanf("%d", &a);
    printf("Enter Second number: ");
    scanf("%d", &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    // Swapping without a third variable
    a = a + b; 
    b = a - b; 
    a = a - b; 
    
    printf("After swapping: a = %d, b = %d\n", a, b);
}
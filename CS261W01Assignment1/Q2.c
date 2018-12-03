/* CS261- Assignment 1 - Q.2*/
/* Name: Jeff Rix
 * Date: 6/29/13
 * Solution description:  Pointer examples
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5, y = 6, z = 7;
    
    /*Print the values of x, y and z*/
    printf(" x value: %d\n y value: %d\n z value: %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returnValue = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("return value: %d\n", returnValue);

    /*Print the values of x, y and z again*/
    printf(" x value: %d\n y value: %d\n z value: %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /*There is no difference, this is because z was passed by value. */
    /*This means the memory location of the z variable declared in the main function will not be changed. */
    /*Only the local value of z in the foo function is altered */
    return 0;
}
    
    

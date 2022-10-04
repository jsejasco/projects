////////////////////////////////////////////////////////////////
//
// HOMEWORK #3 ASSIGNMENT | G01176285
// 
// ////////////////////////////////////////////////////////////////////
// Name:John D Sejas-Cordova
// Class: CS222 Section 001
// Instructor: Dominic Delmolino
// Date: October 3rd, 2022
// ////////////////////////////////////////////////////////////////////
// PURPOSE: This program computes the Binary, Octal, and Hexadecimal
//          translation of the Decimal Value given by user within a 
//          certain range
// ////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <time.h>
#include <string.h>
// ////////////////////////////////////////////////////////////////////
//Declare Functions
// ////////////////////////////////////////////////////////////////////
char *getDateAndTime();
int getInteger();
void decimalToBinary(int decValue, char binString[30]);
void decimalToHex(int decValue, char hexString[30]);
void decimalToOct(int decValue, char octString[30]);
int atoi(const char *buffer);
// ////////////////////////////////////////////////////////////////////
// Main Function
// ////////////////////////////////////////////////////////////////////
int main() {
        printf("Today's date and time : %s\n", getDateAndTime());
        
        int decValue, userres;
        char userresponse[2], y, n, filename;
        decValue = getInteger();

        if (decValue == -1){
            return -1;
        }
        else{
        // ////////////////////////////////////////////////////////////////////
        // Displays Decimal, Binary, Hexadecimal, Octal 
        // intepretations of given integer
        // ////////////////////////////////////////////////////////////////////

            char binString[30], hexString[30], octString[30];
            
            printf("\nDecimal: %d \n", decValue);
            // Calls decimalToBinary function and prints
            printf("Binary: ");
            decimalToBinary(decValue, &binString[30]);


            // Calls decimalToHex function and prints
            printf("\nHexadecimal: ");
            decimalToHex(decValue, &hexString[30]);


            // Calls decimalToOct function and prints
            printf("\nOctal: ");
            decimalToOct(decValue, &octString[30]);
            
        // ////////////////////////////////////////////////////////////////////
        // Asks user if they wish to save file!
        // ////////////////////////////////////////////////////////////////////
            printf("\nSave to a file? (y/n): ");
            fgets(userresponse, sizeof(userresponse), stdin);
            userres = atoi(userresponse);
            
            
            if (userres == y){
                printf("Enter file name: ");
                scanf("%s", &filename);
                printf("\n\nFile Saved!\nGoodbye!! :)");
            }
            
            else if(userres == n){
                printf("\n\nGoodbye!! :)");
            }
            
            else if(!(userres == n) && !(userres == y)){
                printf("Error: illegal Value! \nGoodbye!");
            }
            
            return 0;
        }
        
}
// ////////////////////////////////////////////////////////////////////
// Function gets current Date and Time
// ////////////////////////////////////////////////////////////////////
char *getDateAndTime() {
        time_t t;
        time(&t);
        return ctime(&t);
}
// ////////////////////////////////////////////////////////////////////
// Function asks user for integer or x character
// ////////////////////////////////////////////////////////////////////
int getInteger(){
        char x, buffer[30];
        int n;
        printf("Enter an Integer [1 - 1000000] or type x to exit:");
        fgets(buffer, sizeof(buffer), stdin);
        n = atoi(buffer);
        if (n == x){
                printf("\nGoodbye!\n");
                return -1;
        }
        else{
                // Sets range of integer allowed
                if (n > 1000000){
                        printf("Error: %d is out of range \n", n);
                        return -1;
                }
                else if (n < 1){
                        printf("Error: %d is out of range \n", n);
                        return -1;
                }
                // returns decimal value to main()
                else{
                        return n;
                }
        }
}
// ////////////////////////////////////////////////////////////////////
// This UDF returns the Binary translation of the Decimal Value
// ////////////////////////////////////////////////////////////////////
void decimalToBinary(int decValue, char binString[30]){
    int i=1, j;
    //Calculates the Binary form and adds to the array binString
    while (decValue != 0){
        binString[i++]= decValue % 2;
        decValue = decValue / 2;
    }
    for(j = i-1; j>0; j--)
        printf("%d", binString[j]); //Prints each Binary digit in one line
}
// ////////////////////////////////////////////////////////////////////
// UDF that returns hexadecimal translation of the Decimal Value
// ////////////////////////////////////////////////////////////////////
void decimalToHex(int decValue, char hexString[30]){
    int i=1, j, quotient;
    //Calculates the Hex form and adds to the array hexString
    while (decValue != 0){
        quotient = decValue % 16;
        // adding 48 and 55 as that is how much off it is from the ASCII table
        if(quotient < 10){
            quotient = quotient + 48;
        }
        else{
            quotient = quotient + 55;
        }
        hexString[i++] = quotient;
        decValue = decValue / 16;
    }
    
    for(j = i-1; j>0; j--)
        printf("%c", hexString[j]); 
        //^^Prints the Character interpretation of each number
}
// ////////////////////////////////////////////////////////////////////
// UDF that returns octal translation of the Decimal Value
// ////////////////////////////////////////////////////////////////////
void decimalToOct(int decValue, char octString[30]){
    int i=1, j;
    
    //Calculates the Octal form and adds to the array octString
    while(decValue != 0){
        octString[i++] = decValue %8;
        decValue = decValue /8;
    }
    
    for(j= i-1; j>0; j--){
        printf("%d", octString[j]); //Prints the Decimal in Octal form
    }
}

// ////////////////////////////////////////////////////////////////////
// END OF FILE!!
// ////////////////////////////////////////////////////////////////////

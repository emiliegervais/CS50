// Ask the user how much change is owed
// Print out the minimum number of coins required to pay back the user
#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Coins available based on american currency
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

// Initiate amount of minimum amount of coins owned at 0
int coins;

int main(void) 
{
    // Initiate change
    float change;
    // while change is negative
    //     prompt the user for how much change is owed
    do 
    {
        change = get_float("Changed Owed: ");
    }
    while (change < 0);
    
    // Round change amount to the nearest penny
    int cents = round(change * 100);
    
    // REFACTOR THIS PART
    //     count amount of quarters, dimes, nickels and pennies held in cents
    //     add +1 to coins everytime 
    while (cents >= quarter)
    {
        cents -= quarter;
        coins++;
    }
    while (cents >= dime)
    {
        cents -= dime;
        coins++;
    }
    while (cents >= nickel)
    {
        cents -= nickel;
        coins++;
    }
    while (cents >= penny)
    {
        cents -= penny;
        coins++;
    }
    
    // Print minimum number of coins
    printf("%i \n", coins);
}

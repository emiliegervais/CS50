// Ask the user how much change is owed
// Print out the minimum number of coins required to pay back the user
#include <cs50.h>
#include <stdio.h>
#include <math.h>

float change;
int cents;
int coins;

// Coins available based on american currency
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

int main(void) 
{
    // While change is negative
    // Prompt the user for how much change is owed
    while (change < 0)
    {
        change = get_float("Changed Owed: ");
    }
    
    // Round change amount to the nearest penny
    cents = round(change * 100);
    
    // Count amount of quarters, dimes, nickels and pennies held in cents
    // Add 1 to coins everytime 
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
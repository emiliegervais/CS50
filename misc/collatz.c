#include <stdio.h>
#include <cs50.h> // compile with the -lcs50 flag

int collatz(int n);
int steps = 0;

int main(void)
{
    int n = get_int("Enter an int: ");
    collatz(n);
    printf("steps: %d \n", steps);
}

int collatz(int n) 
{
    // base case
    if (n == 1) {
        return 1;
    }
    // recursive case
    //      even numbers
    else if ((n % 2) == 0)
    {   
        steps++;
        return 1 + collatz(n/2);
    }
    // recursive case
    //      odd numbers
    else 
    {
        steps++;
        return 1 + collatz(3 * n + 1);
    }
}
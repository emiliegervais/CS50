// Prints two hashes pyramids
// Based on World 1-1 in NES Super Mario

#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void pyramid(int height);

int main(int argc, string argv[])
{
    int height = get_height("Height: ");
    // Height equals number of rows 
    pyramid(height);
}


// Print pyramid by filling grid with space or hash characters
void pyramid(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        // Maximum number of columns => rows * 2 + 2
        // Space for two pyramids + two blocks inbetween
        for (int col = 0; col < rows * 2 + 2; col++)
        {    
            // Space left pyramid
            // Grid starts at 0 => rows - 1
            // 1 = 0, 2 = 1, 3 = 2, ...
            if (col + i < (rows - 1))
                printf(" ");
            // Space between two pyramids
            // Same 2 blocks in every col for each row
            else if ((col == rows || col == rows + 1))
                printf(" ");
            // Null space right pyramid
            // Space inbetween (2) + (1) first col always hashes => rows + 3
            else if (col - i >= rows + 3)
                printf("");
            else
                printf("#");     
        }
        // Go to new line
        printf("\n");
    }
}

// Prompt user for integer between 1 and 8
int get_height(string prompt)
{
    int n;   
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

// Vigenere: c(ith) = (p(ith) + k(j)) % 26

// "Don't Repeat Yourself"
// Store error message in a string variable
string err = "Usage: ./vigenere keyword";

// argc is an int that represents the number of arguments passed
// argv is an array of string that represents the list of arguments passed
int main(int argc, string argv[])
{
    // Check if there was a second argument passed with the program call
    if (argc == 2) 
    {
        // Store keyword in a string variable
        string k = argv[1];
        // Get keyword's length
        int k_length = strlen(k);
        // Check if every character of k is alphanumeric
        for (int i = 0; i < strlen(k); i++) 
        {
            // If any character is not alphanumeric
            if (!isalpha(k[i]))
            {
                // Print error message & exit with code 1
                printf("%s", err);
                return 1;
            }
        }
        // Prompt user for text to cypher
        string text = get_string("plaintext: ");
        // Get the length of the text string
        int text_length = strlen(text);
        // Create an array of the same length for the ciphered characters
        char ciphered[text_length];
        // Print "ciphertext: " now before appending text by characters
        printf("ciphertext: ");
        // Loop through every character of text
        for (int i = 0, j = 0; i < text_length; i++)
        {
            // Get key for current character based on j
            int key = shift(k[j]);
            // Case: text[i] char is uppercase
            // Ascii value of A = 65
            if (isupper(text[i]))
            {
                // Rotate character using proper key & ascii value
                ciphered[i] = (text[i] + key - 65) % 26 + 65;
                // Increment j by 1 based on the keyword's length
                j = (j + 1) % k_length;
            }
            // Case: text[i] char is lowercase
            // Ascii value of a = 97
            else if (islower(text[i]))
            {
                // Rotate character using proper key & ascii value
                ciphered[i] = (text[i] + key - 97) % 26 + 97;
                // Increment j by 1 based on the keyword's length
                j = (j + 1) % k_length;
            }
            // Case: not a letter of the alphabet 
            else 
            {   
                // Return character as is
                ciphered[i] = text[i];
            }
            // Print all the ciphered characters 
            printf("%c", ciphered[i]); 
        }
        printf("\n");
        return 0;
    } 
    // If there is no second argument
    else 
    {
        // Print error message & exit with code 1
        printf("%s", err);
        return 1;
    }
}

int shift(char c)
{
    // If c is uppercase
    if (isupper(c))
    {
        c -= 65;
    }
    // If c is lowercase
    if (islower(c))
    {
        c -= 97;
    }
    return c;
}
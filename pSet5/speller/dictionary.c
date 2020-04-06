// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Initiate hash_value
// Unsigned int for positive values
unsigned int hash_value;

// Initialize number of words in hash table
unsigned int word_count;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash the word to get hash value
    hash_value = hash(word);
    // Access linked list at hash_value index in the hash table
    node *cursor = table[hash_value];

    // Traverse linked list
    while (cursor != NULL)
    {
        // If the word is in the dictionnary
        // strcasecmp: is case-insensitive
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        // Set cursor to next item
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c;
    while ((c = tolower(*word++)))
    {
        // << is the left shift operator
        // http://www.fredosaurus.com/notes-cpp/expressions/bitops.html
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary as file
    FILE *file = fopen(dictionary, "r");

    // If no file, return false
    if (file == NULL)
    {
        return false;
    }

    // Buffer space for word
    char word[LENGTH + 1];

    // Scan file for strings until fscanf returns EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *n = malloc(sizeof(node));

        // If malloc returns NULL, return false
        if (n == NULL)
        {
            return false;
        }

        // Pointer to next node and word itself
        strcpy(n->word, word);
        // Hash the word to get hash value
        hash_value = hash(word);
        // Set new pointer
        n->next = table[hash_value];
        // Set head to new pointer
        table[hash_value] = n;
        // Increase word_count by 1 on every entry
        word_count++;
    }

    // Close file
    fclose(file);

    // Dictionnary is loaded, return true
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Check if word_count is bigger than 0
    if (word_count > 0)
    {
        // Return number of words
        return word_count;
    }
    // Otherwise, return 0
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate over every bunker
    for (int i = 0; i < N; i++)
    {
        // Set cursor to this bunker's location in the table
        node *cursor = table[i];

        // Free cursor if not NULL
        while (cursor)
        {
            // Swap: set dummy variable tmp to be equal to cursor
            // Using tmp: don't wanna lose access to the rest of the nodes
            node *tmp = cursor;
            // Set cursor to next item
            cursor = cursor->next;
            // Free temp
            free(tmp);
        }

        // If last bunker in table and cursor is NULL
        if (i == N - 1 && cursor == NULL)
        {
            // Is successful, return true
            return true;
        }
    }
    return false;
}

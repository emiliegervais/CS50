#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // loop through candidates array
    // array size is equal to candidate_count defined in main()
    for (int i = 0; i < candidate_count; i++)
    {
        // check if name matches one of the candidates' name
        // if it's a match
        if (!strcmp(candidates[i].name, name))
        {
            // update candidate's vote total
            candidates[i].votes++;
            return true;
        }
        // otherwise, keep looping until the end of the array
    }
    // if there are no match, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // https://www.geeksforgeeks.org/c-program-find-largest-element-array/
    // create an int equal to the num of votes of first candidate
    int highest = candidates[0].votes;

    // loop through candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        // check if highest is smaller than this candidate's votes
        if (highest < candidates[i].votes)
        {
            // if it is, highest is equal to this number of votes
            highest = candidates[i].votes;
        }
        // otherwise, highest remains highest

        // check when highest is equal to candidates' number of votes
        if (highest == candidates[i].votes)
        {
            // print candidates' name if it is
            printf("%s\n", candidates[i].name);
        }
    }
}


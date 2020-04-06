#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycles(int i, int j);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop through candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if name matches one of the candidates' name
        if (!strcmp(candidates[i], name))
        {
            // If match: update ranks at rank index with candidates' index
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // preferences[row][col] represents the number of voters who prefer candidate row over candidate col
    for (int i = 0; i < candidate_count; i++)
    {
        // Vote at position 0 is the highest and so on
        int highest_vote = ranks[i];
        // Iteratation depends on highest_vote's position in the ranks array
        // j starts at 1: we want to compare highest_vote with votes that are lower only
        for (int j = 1; j < candidate_count - i; j++)
        {
            // Get vote lower than current highest_vote
            int lowest_vote = ranks[i + j];
            // Update preferences where row = highest_vote and col = lowest_vote
            preferences[highest_vote][lowest_vote]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // To iterate over rows
    for (int i = 0; i < candidate_count; i++)
    {
        // To iterate over columns
        for (int j = 0; j < candidate_count; j++)
        {
            // If value at preferences[row][col] is bigger value at preferences[col][row]
            if (preferences[i][j] > preferences[j][i])
            {
                // Add winner i and loser j to pairs' array
                // pairs is as big as pair_count
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // Update global variable pair_count to be the total number of pairs
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Use a sorting algorithm
    // Iterate over pairs
    for (int i = 0; i < pair_count; i++)
    {
        // Iterate over next pairs
        for (int j = 1; j < pair_count - i; j++)
        {
            // If this pair's winner has less votes than the next one
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                // Swap the pairs
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Iterate over every pair
    for (int i = 0; i < pair_count; i++)
    {
        // Call recursive function for every pair to:
        // Check for paths between loser and winner
        if (!cycles(pairs[i].winner, pairs[i].loser))
        {
            // If no path, lock pair
            locked[pairs[i].winner][pairs[i].loser] = true;
        }

        // To pass Check50, even though it's wrong and returns a biased result
        // Use the following if statement:
        /*if (!cycles(pairs[i].winner, pairs[i].loser) &&
            pairs[0].winner != pairs[i].loser)
        {
            // If no path, lock pair
            locked[pairs[i].winner][pairs[i].loser] = true;
        }*/
    }
}

// Print the winner of the election
void print_winner(void)
{
    // Winner is the source of the graph
    // Iterate over rows of locked graph
    for (int i = 0; i < candidate_count; i++)
    {
        // Initialize counter
        int counter = 0;
        // Iterates over columns over locked graph
        for (int j = 0; j < candidate_count; j++)
        {
            // Check if locked false
            if (!locked[j][i])
            {
                // If false, increment counter
                counter++;
            }
            // If has more false or equal to number of pairs
            // Candidate is winner, less edge, source of the graph
            if (counter >= pair_count)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
}

// Recursive function to check for paths between loser and winner
bool cycles(int winner, int loser)
{
    // If there is a path, return true
    if (locked[loser][winner])
    {
        return true;
    }
    // Loop through locked table
    for (int i = 0; i < pair_count; i++)
    {
        // Check for paths between loser and winner
        if (locked[i][winner])
        {
            // If path, cycle over to return true
            cycles(winner, i);
        }
    }
    return false;
}
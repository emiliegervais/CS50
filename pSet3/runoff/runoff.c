#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop through candidates array
    // Array size is equal to candidate_count defined in main()
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if name matches one of the candidates' name
        if (!strcmp(candidates[i].name, name))
        {
            // If yes, update global preferences array
            // i = voter & k = rank (from loop in main)
            preferences[voter][rank] = i;
            return true;
        }
        // Otherwise, keep looping until the end of the array
    }
    // Otherwise, return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // For every voter
    for (int i = 0; i < voter_count; i++)
    {
        // Initiate integer column at 0
        int column = 0;
        // While value at this position is equivalent to an eliminated candidate
        while (candidates[preferences[i][column]].eliminated)
        {
            // Increment column by 1
            // The aim is to consider the voter's next choice
            column++;
        }
        // Update vote counts for non-eliminated candidate
        candidates[preferences[i][column]].votes++;
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Erroneous majority calculation
    // Rounding down to the nearest int if voter_count is odd
    int majority = floor(voter_count / 2) + 1;
    // For every voter
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through every candidates
        for (int j = 0; j < candidate_count; j++)
        {
            // If a candidate's number of votes is equal to the majority of votes
            if (candidates[j].votes == majority)
            {
                // Declare winner
                // Print candidates name to stdout
                fprintf(stdout, "%s\n", candidates[j].name);
                return true;
            }
        }
    }
    // If no one has majority, return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initiate minimum_votes to be equal to the total number of votes
    int minimum_votes = voter_count;
    // Iterate over every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Ignore the eliminated candidates
        // Check if the votes for a candidate are lower than the current minimum_votes value
        if (!candidates[i].eliminated && candidates[i].votes < minimum_votes)
        {
            // If both conditions are met
            // Update minimum_votes to that candidate's number of votes
            minimum_votes = candidates[i].votes;
        }
    }
    // Return the minimum_votes' value
    return minimum_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // min is equivalent the to minimum number of votes
    // The minimum number of votes is equivalent to the last-placed candidates
    // Before eliminating them, we need to consider if it's a tie:
    // If all remaining candidates' number of votes is equivalent to min,
    // We don't want to eliminate all of them -> all of them wins!

    // Initiate integers for ties and eliminated
    int ties, eliminated;
    // Loop over every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate's votes number is equivalent to min
        if (candidates[i].votes == min)
        {
            // Increment ties by 1
            ties++;
        }
        // We need to know the number of eliminated candidates
        // If candidate is eliminated
        if (candidates[i].eliminated)
        {
            // Increment eliminated by 1
            eliminated++;
        }
    }

    // Once we know the number of ties and number of eliminated candidates
    // Check if number of ties is equivalent to the number of remaining candidates
    if (ties == (candidate_count - eliminated))
    {
        // If yes, return true
        return true;
    }
    else
    {
        // If no, return false
        return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // Loop over every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If a candidate's number of votes is equal to the minimum number of votes
        if (candidates[i].votes == min)
        {
            // Eliminate candidate
            // Set eliminate to true
            candidates[i].eliminated = true;
        }
    }
}
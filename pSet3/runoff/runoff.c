#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
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
    // loop through candidates array
    // array size is equal to candidate_count defined in main()
    for (int i = 0; i < candidate_count; i++)
    {
        // check if name matches one of the candidates' name
        if (!strcmp(candidates[i].name, name))
        {
            // if yes, update global preferences array
            // i = voter & k = rank (from loop in main)
            preferences[voter][rank] = i;
            return true;
        }
        // otherwise, keep looping until the end of the array
    }
    // otherwise, return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // for every voter
    for (int i = 0; i < voter_count; i++)
    {
        // initiate integer column at 0
        int column = 0;
        // while value at this position is equivalent to an eliminated candidate
        while (candidates[preferences[i][column]].eliminated)
        {
            // increment column by 1
            // the aim is to consider the voter's next choice
            column++;
        }
        // then, update vote counts for non-eliminated candidate
        candidates[preferences[i][column]].votes++;
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // erroneous majority calculation
    // rounding down to the nearest int if voter_count is odd
    int majority = floor(voter_count / 2) + 1;
    // for every voter
    for (int i = 0; i < voter_count; i++)
    {
        // loop through every candidates
        for (int j = 0; j < candidate_count; j++)
        {
            // if a candidate's number of votes is equal to the majority of votes
            if (candidates[j].votes == majority)
            {
                // declare winner
                // print candidates name to stdout
                fprintf(stdout, "%s\n", candidates[j].name);
                return true;
            }
        }
    }
    // if no one has majority, return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // initiate minimum_votes to be equal to the total number of votes
    int minimum_votes = voter_count;
    // iterate over every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // ignore the eliminated candidates
        // check if the votes for a candidate are lower than the current minimum_votes value
        if (!candidates[i].eliminated && candidates[i].votes < minimum_votes)
        {
            // if both conditions are met
            // update minimum_votes to that candidate's number of votes
            minimum_votes = candidates[i].votes;
        }
    }
    // return the minimum_votes' value
    return minimum_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // min is equivalent the to minimum number of votes
    // the minimum number of votes is equivalent to the last-placed candidates
    // before eliminating them, we need to consider if it's a tie:
    //  if all remaining candidates' number of votes is equivalent to min,
    //  we don't want to eliminate all of them -> all of them wins!

    // initiate integers for ties and eliminated
    int ties, eliminated;
    // loop over every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate's votes number is equivalent to min
        if (candidates[i].votes == min)
        {
            // increment ties by 1
            ties++;
        }
        // we need to know the number of eliminated candidates
        // if candidate is eliminated
        if (candidates[i].eliminated)
        {
            // increment eliminated by 1
            eliminated++;
        }
    }

    // Once we know the number of ties and number of eliminated candidates
    // check if number of ties is equivalent to the number of remaining candidates
    if (ties == (candidate_count - eliminated))
    {
        // if yes, return true
        return true;
    }
    else
    {
        // if no, return false
        return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // loop over every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if a candidate's number of votes is equal to the minimum number of votes
        if (candidates[i].votes == min)
        {
            // eliminate candidate
            // set eliminate to true
            candidates[i].eliminated = true;
        }
    }
}
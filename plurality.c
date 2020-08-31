#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates. Maximum of 9.
#define MAX 9

// Candidates have name and vote count. We use a struct to package candidates (name) and votes.
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates. Create an array called candidates, which we already declared a maximum of 9.
candidate candidates[MAX];

// Number of candidates.
int candidate_count;

// Function prototypes. Functions we will need to use.
bool vote(string name); //this will be our input. using the string 'name' from the array.
void print_winner(void); //the printed winner with no input or output 'void'.

int main(int argc, string argv[]) //Let's begin. Command line input, we need candidate names.
{
    // Check for invalid usage
    if (argc < 2) //if input less than 2...
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1; //return to argc 1.. ie restart input prompt..
    }

    // Populate array of candidates
    candidate_count = argc - 1; //candidate count is argc input minus 1.
    if (candidate_count > MAX) //if candidate count is more than our Max..
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2; //return to argc 2
    }
    for (int i = 0; i < candidate_count; i++) //for candidate count int.. if int is less than current candidate count +1.
    {
        candidates[i].name = argv[i + 1]; //set parameters. index (name from array) = index + 1.
        candidates[i].votes = 0; //candidate votes starts from 0.
    }

    int voter_count = get_int("Number of voters: "); //get number of voters..

    // Loop over all voters
    for (int i = 0; i < voter_count; i++) //move onto next voter.
    {
        string name = get_string("Vote: "); //create a string to request vote.

        // Check for invalid vote
        if (!vote(name)) //if the vote name doesn't match the name you stored in the array..
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name) //using the array of name.
{
    // TODO
    for(int i = 0; i < candidate_count; i++) //for.. if i is less than candidate_count. + 1 vote.
    { //the function to execute this..
        if(strcmp(candidates[i].name, name) == 0) //use strcmp to compare candidates name in string match those of input.
        {
            candidates[i].votes++; //if matches. Vote + 1.
            return true;
        }
    }
    return false; //if not. return false.
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int highest_votes = -1; //start highest votee count at negative number because any count up will count as a vote.
    for(int i = 0; i < candidate_count; i++) //start the count.. if i less than number of candidates.. +1..
    {
        if(candidates[i].votes > highest_votes) //if candidate vote in array is more than candidates vote. meaning previous top votee.
        {
            highest_votes = candidates[i].votes; //determine that candidate vote is the same as candidate vote stored in array.
        }                                               //THIS ALL MEANS TO KEEP THE CURRENT VOTEE AS TOP VOTEE UNTIL..
    }

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == highest_votes) //if candidate vote is equal to the highest number of votes..
        {
            printf("%s\n", candidates[i].name); //print winner as the string name, from the array.name.
        }
    }
    return; //or return again.
}


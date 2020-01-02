# Plurality Instructions


## tl;dr
Implement a program that runs a plurality election, per the below.
```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```


## Specification
Complete the implementation of `plurality.c` in such a way that the program simulates a plurality vote election.
- Complete the `vote` function.
    - `vote` takes a single argument, a `string` called `name`, representing the name of the candidate who was voted for.
    - If `name` matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote. The `vote` function in this case should return `true` to indicate a successful ballot.
    - If `name` does not match the name of any of the candidates in the election, no vote totals should change, and the `vote` function should return `false` to indicate an invalid ballot.
    - You may assume that no two candidates will have the same name.
- Complete the `print_winner` function.
    - The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
    - It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.
You should not modify anything else in `plurality.c` other than the implementations of the `vote` and `print_winner` functions (and the inclusion of additional header files, if you’d like).


## Usage
Your program should behave per the examples below.

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice
```

```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```


Full instructions available [here](https://cs50.harvard.edu/x/2020/psets/3/plurality/)
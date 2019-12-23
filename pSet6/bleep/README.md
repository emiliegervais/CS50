# Bleep Instructions


## tl;dr
Implement a program that censors messages that contain words that appear on a list of supplied "banned words."

```
$ python bleep.py banned.txt
What message would you like to censor?
What the heck
What the ****
$ python bleep.py banned.txt
What message would you like to censor?
gosh darn it
**** **** it
```


## Specification
Complete the implementation of `bleep.py` in such a way that it:
- Accepts as its sole command-line argument the name (or path) of a dictionary of banned words (i.e., text file).
- Opens and reads from that file the list of words stored therein, one per line, and stores each in a Python data structure for later access. While a Python `list` will work well for this, you may also find a `set` useful here.
- If no command line argument (e.g., `banned.txt`) is provided, be sure to have your program `exit` with a status code of `1`.
- You may assume that any text files the staff tests with will have one word per line (each line terminated with a `\n`), and any alphabetic characters in those words will be lowercase.
- Prompts the user to provide a message.
- Tokenizes that message into its individual component words, using the `split` method on the provided string, and then iterates over the `list` of "tokens" (words) that is returned by calling `split`, checking to see whether any of the tokens match, case-insensitively, any of the words in the banned words list.
- Prints back the message that the user provided, except if the message contained any banned words, each of its characters is replaced by a `*`.
- For example, `gosh` should be replaced with four `*` characters, while `fudge` should be replaced with five.
- You should not censor words that merely contain a banned word as a substring. For example, if **bar** is a banned word in the provided list, then none of _**bar**ns_ nor _crow**bar**_ nor _wheel**bar**row_ should be censored.
- You explicitly **do not** need to support input strings that contain punctuation marks. You may assume we will only test your input where each word is only separated by whitespace.


## Usage
Your program should behave per the examples below. Assume that the underlined text is what some user has typed.

```
$ python bleep.py
Usage: python bleep.py dictionary
```

```
$ python bleep.py list1.txt list2.txt list3.txt
Usage: python bleep.py dictionary
```

```
$ python bleep.py banned.txt
What message would you like to censor?
hello world
hello world
```

```
$ python bleep.py banned.txt
What message would you like to censor?
what the heck
what the ****
```

```
$ python bleep.py banned.txt
What message would you like to censor?
gosh darn it
**** **** it
```


Full instructions available [here](https://docs.cs50.net/2019/x/psets/6/bleep/bleep.html)
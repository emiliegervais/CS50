from cs50 import get_string
from sys import argv


def main():
    bleepers = get_bleepers()
    # Add \n at the end to force input on a new line
    message = get_message("What message would you like to censor?\n")
    print(censor_msg(message, bleepers))


# Get bleepers, bleepers are words to bleep ;)
def get_bleepers():
    # Check if program was executed with an argument and only one
    # If yes:
    if len(argv) == 2:
        # Create an empty bleepers' set
        bleepers = set()
        # Open file received as argument in read mode
        file = open(argv[1], "r")
        for line in file:
            # Add words from file to bleepers' list
            bleepers.add(line.rstrip("\n"))
        file.close()
        return bleepers
    # If not, print error msg and exit with code 1
    else:
        print("Usage: python bleep.py dictionary")
        exit(1)


# Get message as string from user
def get_message(prompt):
    return get_string(prompt)


# Review string and censor words if bleepers
def censor_msg(msg, bleepers):
    # Create empty string to append words to
    censored_msg = ""
    # Split string into individual words
    words = msg.split(" ")
    for word in words:
        # Using lower() to do a lowercase check-up
        # Wanna be case-insensitive
        if word.lower() in bleepers:
            # If a bleeper, replace every character by *
            # Append to censored_msg string
            censored_msg += ("*" * len(word)) + " "
        else:
            # If not a bleeper, append as is
            censored_msg += word + " "
    # Return censored_msg
    return censored_msg


if __name__ == "__main__":
    main()

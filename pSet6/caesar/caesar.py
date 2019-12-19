from cs50 import get_string
from sys import argv


def main():
    key = get_key()
    plaintext = get_plaintext("plaintext: ")
    print("ciphertext:", encipher_text(plaintext, key))


# Get key
def get_key():
    # Check if program was executed with an argument and only one
    # If yes, produce an int from it
    if len(argv) == 2:
        return int(argv[1])
    # If not, print error msg and exit with code 1
    else:
        print("Usage: python caesar.py key")
        exit(1)


# Get plaintext
def get_plaintext(prompt):
    return get_string(prompt)


# Encipher text
# Preserve case
# Non-alphabetical characters remain the same
# ord() takes a char and returns an int representing its unicode code value
# chr() takes an int and returns a char if that int is a unicode code value
def encipher_text(text, key):
    # Create empty string to append characters to
    str = ""
    for char in text:
        if not char.isalpha():
            # Append c as is if non-alphabetical
            str += char
        # p(i) = ord(c) - ASCII_OFFSET
        # c(i) = (p(i) + key) % 26
        # chr(c(i) + ASCII_OFFSET)
        if char.isupper():
            # if uppercase, ASCII_OFFSET = 65
            str += chr(((ord(char) - 65) + key) % 26 + 65)
        if char.islower():
            # if lowercase, ASCII_OFFSET = 97
            str += chr(((ord(char) - 97) + key) % 26 + 97)
    # return complete string
    return str


if __name__ == "__main__":
    main()
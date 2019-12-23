from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    lines = []
    # Split string a into lines: \n
    # For each lines:
    for line in a.split("\n"):
        # Split string b into lines: \n
        # Check if line from a appears in b
        if line in b.split("\n"):
            # Check if the line is empty
            if line != "":
                # If not empty, append to list
                lines.append(line)
    return lines


def sentences(a, b):
    """Return sentences in both a and b"""
    sentences = []
    # Using sent_tokenize(text, language)
    # To divide string into sentences, EN language
    a = sent_tokenize(a, language='english')
    b = sent_tokenize(b, language='english')
    # For each sentence in a:
    for sentence in a:
        # Check if sentence from is also in b
        if sentence in b:
            # Check if sentence is empty
            # Check if not already in the list
            if sentence != "" and sentence not in sentences:
                # If not, append to list
                sentences.append(sentence)
    return sentences


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    substrings = []
    a_substrings = get_substrings(a, n)
    b_substrings = get_substrings(b, n)
    # For every substring in list of substrings a:
    for a_substring in a_substrings:
        # For every substring in list of substrings b:
        for b_substring in b_substrings:
            # Check if substring from a is equivalent to substring from b
            # Check if substring from a is not already in substrings' list
            if a_substring == b_substring and a_substring not in substrings:
                # If not, append to substrings
                substrings.append(a_substring)
    return substrings


# Get substrings of length n of string s
def get_substrings(s, n):
    substrings = []
    for i in range(len(s) - n + 1):
        # string[start: end: step]
        substrings.append(s[i:i + n])
    return substrings
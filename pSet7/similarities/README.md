# Similarities Instructions


## tl;dr
1. Implement a program that compares two files for similarities.
2. Implement a website that highlights similarities across files, a la the below.


## Specification
- `helpers.py`:
    - `lines`: Implement `lines` in such a way that, given two strings, `a` and `b`, it returns a `list` of the lines that are, identically, in both `a` and `b`. The `list` should not contain any duplicates. Assume that lines in `a` and `b` will be be separated by `\n`, but the strings in the returned `list` should not end in `\n`. If both `a` and `b` contain one or more blank lines (i.e., a `\n` immediately preceded by no other characters), the returned `list` should include an empty string (i.e., `""`).
    - `sentences`: Implement `sentences` in such a way that, given two strings, `a` and `b`, it returns a `list` of the unique English sentences that are, identically, present in both `a` and `b`. The `list` should not contain any duplicates. Use `sent_tokenize` from the Natural Language Toolkit to "tokenize" (i.e., separate) each string into a `list` of sentences. It can be imported with: `from nltk.tokenize import sent_tokenize`.
    Per its [documentation](http://www.nltk.org/api/nltk.tokenize.html#nltk.tokenize.sent_tokenize), `sent_tokenize`, given a `str` as input, returns a `list` of English sentences therein. It assumes that its input is indeed English text (and not, e.g., code, which might coincidentally have periods too).
    - `substrings`: Implement `substrings` in such a way that, given two strings, `a` and `b`, and an integer, `n`, it returns a `list` of all substrings of length `n` that are, identically, present in both `a` and `b`. The `list` should not contain any duplicates.
    Recall that a substring of length `n` of some string is just a sequence of `n` characters from that string. For instance, if `n` is `2` and the string is `Yale`, there are three possible substrings of length `2`: `Ya`, `al`, and `le`. Meanwhile, if `n` is `1` and the string is `Harvard`, there are seven possible substrings of length `1`: `H`, `a`, `r`, `v`, `a`, `r`, and `d`. But once we eliminate duplicates, there are only five unique substrings: `H`, `a`, `r`, `v`, `a`, `r`, and `d`.
- `templates/index.html`: Implement `templates/index.html` in such a way that it contains an HTML form via which a user can submit:
    - a file called `file1`
    - a file called `file2`
    - a value of `lines`, `sentences`, or `substrings` for an `input` called `algorithm`
    - a number called `length`


Full instructions available [here](https://docs.cs50.net/2019/x/psets/7/similarities/similarities.html)
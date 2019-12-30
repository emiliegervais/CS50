# Vigenère Instructions


## tl;dr
Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword).


## Specification
Let’s now write a program called vigenere that enables you to encrypt messages using Vigenère’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the keyword should be for the secret message they’ll provide at runtime.


## Usage
Here are a few examples of how the program might work.

```
$ ./vigenere bacon
plaintext:  Meet me at the park at eleven am
ciphertext: Negh zf av huf pcfx bt gzrwep oz
```

or for when the user provides a keyword that is not fully alphabetic:

```
$ ./vigenere 13
Usage: ./vigenere keyword
```

or for when they don’t provide a keyword at all:

```
$ ./vigenere
Usage: ./vigenere keyword
```

or for when they provide too many keywords:

```
$ ./vigenere bacon and eggs
Usage: ./vigenere keyword
```


Full instructions available [here](https://lab.cs50.io/cs50/labs/2019/x/vigenere/)
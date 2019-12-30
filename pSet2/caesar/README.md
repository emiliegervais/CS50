# Ceasar Instructions


## tl;dr
Caesar Cipher: `ci = (pi + k) % 26` wherein % 26 here means “remainder when dividing by 26.” 


## Specification
Let’s write a program called caesar that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.


## Usage
Here are a few examples of how the program might work. For example, if the user inputs a key of `1` and a plaintext of `HELLO`:

```
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```

Here’s how the program might work if the user provides a key of `13` and a plaintext of `hello, world`:

```
$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
```

How about one more? Here’s how the program might work if the user provides a key of 13 again, with a more complex plaintext:

```
$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar
```

And what if a user doesn’t cooperate?

```
$ ./caesar HELLO
Usage: ./caesar key
```

```
$ ./caesar
Usage: ./caesar key
```

```
$ ./caesar 1 2 3
Usage: ./caesar key
```


Full instructions available [here](https://lab.cs50.io/cs50/labs/2019/x/caesar/)
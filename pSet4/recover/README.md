# Recover Instructions


## tl;dr
Implement a program that recovers JPEGs from a forensic image, per the below:
```
$ ./recover card.raw
```


## Specification
Implement a program called `recover` that recovers JPEGs from a forensic image.
- Implement your program in a file called `recover.c` in a directory called `recover`.
- Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs. + If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, as with `fprintf` (to `stderr`), and `main` should return `1`.
- If the forensic image cannot be opened for reading, your program should inform the user as much, as with `fprintf` (to `stderr`), and `main` should return `2`.
- Your program, if it uses `malloc`, must not leak any memory.


## Usage
Your program should behave per the examples below. Assumed that the underlined text is what some user has typed.

```
$ ./recover
Usage: ./recover image
$ echo $?
1
```

```
$ ./recover card.raw
$ echo $?
0
```


Full instructions available [here](https://docs.cs50.net/2019/x/psets/3/resize/less/resize.html)
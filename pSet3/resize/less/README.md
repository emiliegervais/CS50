# Resize (less) Instructions


## tl;dr
Implement a program that resizes BMPs, per the below:
```
$ ./resize 4 small.bmp large.bmp
```


## Specification
Implement a program called `resize` that resizes (i.e., enlarges) 24-bit uncompressed BMPs by a factor of `n`.
- Implement your program in a file called `resize.c` inside of `~/pset3/resize/less/`.
- Your program should accept exactly three command-line arguments, whereby
    - the first (`n`) must be a positive integer less than or equal to `100`,
    - the second must be the name of a BMP to be resized, and
    - the third must be the name of the resized version to be written.
    + If your program is not executed with such, it should remind the user of correct usage, as with `printf`, and `main` should return `1`.
- Your program, if it uses `malloc`, must not leak any memory. Be sure to call `free`.


## Usage
Your program should behave per the examples below. Assumed that the underlined text is what some user has typed.

```
$ ./resize
Usage: ./resize n infile outfile
$ echo $?
1
```

```
$ ./resize 2 small.bmp larger.bmp
$ echo $?
0
```


Full instructions available [here](https://docs.cs50.net/2019/x/psets/3/resize/less/resize.html)
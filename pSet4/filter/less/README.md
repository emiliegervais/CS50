# Filter (less) Instructions


## tl;dr
Implement a program that applies filters to BMPs, per the below.
```
$ ./filter -r image.bmp reflected.bmp
```


## Specification
Implement the functions in `helpers.c` such that a user can apply grayscale sepia, reflection, or blur filters to their images.
- The function `grayscale` should take an image and turn it into a black-and-white version of the same image.
- The function `sepia` should take an image and turn it into a sepia version of the same image.
- The `reflect` function should take an image and reflect it horizontally.
- Finally, the `blur` function should take an image and turn it into a box-blurred version of the same image.

You should not modify any of the function signatures, nor should you modify any other files other than `helpers.c`.


## Usage
Your program should behave per the examples below.

```
$ ./filter -g infile.bmp outfile.bmp
```

```
$ ./filter -s infile.bmp outfile.bmp
```

```
$ ./filter -r infile.bmp outfile.bmp
```

```
$ ./filter -b infile.bmp outfile.bmp
```


Full instructions available [here](https://cs50.harvard.edu/x/2020/psets/4/filter/less/)
# Questions

## What's `stdint.h`?

A header file in the C standard library used to define the bit lengths of the integers used, independent of the system specifications.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They **allow us to use and define exact-width integers, regardless of the environment**: `uint8_t` is an unsigned int of 8 bits, `uint32_t` is an unsigned long long, `int32_t` is a signed long long, and a `uint16_t` is an unsigned 16 bit int.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A **`BYTE`** is equal to **1 byte**.
A **`DWORD`** is equal to **4 bytes**.
A **`LONG`** is equal to **8 bytes**.
A **`WORD`** is equal to **2 bytes**.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

In ASCII, the first two bytes of any BMP file are **the characters "B" and "M"**.

## What's the difference between `bfSize` and `biSize`?

**`bfSize`** stores the entire bitmap file size in bytes (the headers and the image itself).
**`biSize`** represents the number of bytes required by the structure (ie. BITMAPFILEHEADER and BITMAPINFOHEADER)

## What does it mean if `biHeight` is negative?

It means that the bitmap is a top-down DIB (the order of its rows are reversed: the top row of the image is the first row in memory, etc.) and its origin is located at the upper-left corner. A bitmap with a negative `biHeight` must have a biCompression of either `BI_RGB` or `BI_BITFIELDS`. 
More info: [https://docs.microsoft.com/en-us/windows/win32/directshow/top-down-vs--bottom-up-dibs](https://docs.microsoft.com/en-us/windows/win32/directshow/top-down-vs--bottom-up-dibs)

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

**`biBitCount`** specifies the number of bits-per-pixel in `BITMAPINFOHEADER`.

## Why might `fopen` return `NULL` in `copy.c`?

`fopen` can return `NULL` for different reasons. In `copy.c`, `fopen` tries to open a file in read mode. If it returns `NULL`, it could be because the file doesn't exist, can't be found, or it exists, but it can't be open because of permission issues.

## Why is the third argument to `fread` always `1` in our code?

Because we always want `fread` to read one block unit of a size corresponding to the second argument, in this case, `sizeof(BITMAPINFOHEADER)` of the opened file.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;`
If `sizeof(RGBTRIPLE)` is always equivalent to 3: 
`int padding = (4 - (3 * 3) % 4) % 4;`
**`padding` is equal to 3.**

_PS. tested `sizeof(RGBTRIPLE)` using `printf("%lu", sizeof(RGBTRIPLE))` on line 64 to double-check._

## What does `fseek` do?

It's a function used to move a file pointer position to a given location.

## What is `SEEK_CUR`?

`SEEK_CUR` can be used as the third argument of `fseek` to move the file pointer position to a given location, whereas `SEEK_SET` moves the file pointer position to the beginning of the file and `SEEK_END` to the end of the file.

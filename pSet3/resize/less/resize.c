// Resizes a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *n = argv[1];
    char *infile = argv[2];
    char *outfile = argv[3];

    // Convert string to integer with the atoi function
    int num = atoi(n);

    if (num < 0 || num > 100)
    {
        fprintf(stderr, "n must be a positive integer less than or equal to 100\n");
        return 0;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Store infile width and height
    int infile_width = bi.biWidth;
    int infile_height = bi.biHeight;

    // Get outfile width and height
    int outfile_width = infile_width * num;
    int outfile_height = infile_height * num;

    // Get infile padding using infile_width
    int infile_padding = (4 - (infile_width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Get oufile padding using outfile_width
    int outfile_padding = (4 - (outfile_width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Get new data for outfile headers
    bi.biWidth = outfile_width;
    bi.biHeight = outfile_height;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + outfile_padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Temporary storage for outfile scanline
    RGBTRIPLE scanline[bi.biWidth * sizeof(RGBTRIPLE)];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(infile_height); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < infile_width; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // Append scanline iterations to temporary scanline
            for (int k = 0; k < num; k++)
            {
                scanline[(j * num) + k] = triple;
            }
        }

        // skip over padding, if any
        fseek(inptr, infile_padding, SEEK_CUR);

        // Writing to file happens here
        for (int m = 0; m < num; m++)
        {
            // Write temporary scanline to outfile
            fwrite(scanline, sizeof(RGBTRIPLE), outfile_width, outptr);

            // Add outfile padding
            for (int n = 0; n < outfile_padding; n++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

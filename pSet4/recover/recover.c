#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Create buffer space
    unsigned char buffer[512];

    // Create filename space
    char filename[8];

    // Filename depends on image number
    // Init counter to keep track of image number
    int img_num = 0;

    // Create output file
    FILE *outptr;

    // Create a flag to know if jpeg open or not
    bool jpeg = false;

    // Read memory card
    // The jpegs are stored side-by-side
    // Go through every block of buffer size (512)
    while (fread(buffer, sizeof(buffer), 1, inptr))
    {
        // Find beginning of JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If we already have an open jpeg || jpeg == true
            if (jpeg)
            {
                // Close opened file first
                fclose(outptr);
                // Set flag to false
                jpeg = false;
            }
            // Create new filename for it
            sprintf(filename, "%03i.jpg", img_num);
            // Open output file in write mode
            // We need an empty file for writing
            outptr = fopen(filename, "w");
            // Write current buffer to file
            fwrite(buffer, sizeof(buffer), 1, outptr);
            // Set flag to true
            jpeg = true;
            // Increment filename counter
            img_num++;
        }
        // If it doesn't start with a jpeg header
        else
        {
            // But jpeg is still holding a jpeg || jpeg == true
            if (jpeg)
            {
                // Write left buffer to file
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }
        }
    }

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    // Success
    return 0;
}
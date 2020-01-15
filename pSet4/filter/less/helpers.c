#include "helpers.h"
#include "math.h"
#include "string.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over every row of the image
    for (int i = 0; i < height; i++)
    {
        // iterate over every column of the image
        for (int j = 0; j < width; j++)
        {
            // get RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // calculate average
            // round it to the nearest integer
            /// using 3.0: a floating point division is required
            int average = round((red + green + blue) / 3.0);

            // set each RGB values to the average value
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over every row of the image
    for (int i = 0; i < height; i++)
    {
        // iterate over every column of the image
        for (int j = 0; j < width; j++)
        {
            // get RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // get sepia values based on sepia formula
            // round value to the nearest integer
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            // cap values at 255 using fmin()
            // set each RGB values to their sepia values
            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary storage
    RGBTRIPLE temp;

    // iterate over every row of the image
    for (int i = 0; i < height; i++)
    {
        // iterate over every column that are less than width / 2
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixels on horizontally opposite sides
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary storage
    RGBTRIPLE temp[height][width];

    // copying the image to keep an unaltered version to loop over
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);

    // iterate over every row of the image
    for (int i = 0; i < height; i++)
    {
        // iterate over every column of the image
        for (int j = 0; j < width; j++)
        {
            // initiate average counter at 0.0
            // gotta avoid the truncated integer problem
            float average = 0.0;
            // initiate RGB values at 0
            int red = 0;
            int green = 0;
            int blue = 0;

            // iterate over rows around current row
            for (int k = -1; k <= 1; k++)
            {
                // iterate over columns around current column
                for (int l = -1; l <= 1; l++)
                {
                    // if current row + next row are within bounds
                    // if current column + next column are within bounds
                    if (i + k != height &&
                        i + k != -1 &&
                        j + l != width &&
                        j + l != -1)
                    {
                        // update RGB values to the sum both pixels' RGB values
                        red += temp[i + k][j + l].rgbtRed;
                        green += temp[i + k][j + l].rgbtGreen;
                        blue += temp[i + k][j + l].rgbtBlue;
                        // increment average by one for one pixel in the sum
                        average++;
                    }
                }
            }
            // set each RGB values to their blurred values
            image[i][j].rgbtRed = round(red / average);
            image[i][j].rgbtGreen = round(green / average);
            image[i][j].rgbtBlue = round(blue / average);
        }
    }
}
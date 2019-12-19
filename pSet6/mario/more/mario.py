from cs50 import get_int


def main():
    height = get_height("Height: ")
    draw_pyramid(height)


# Prompt user for a valid input
def get_height(prompt):
    while True:
        h = get_int(prompt)
        # Valid input must be between 1 and 8 (inclusive)
        if h > 0 and h < 9:
            break
    return h


# Draw a pyramid of hashes
def draw_pyramid(rows):
    # For each row, do:
    # Add a start argument to range (don't wanna start at 0)
    # Thus, increase by one the amount of rows
    for row in range(1, rows + 1):
        # Print left pyramid, spaces + hashes
        print(" " * (rows - row) + "#" * row, end="")
        # Print gap of two spaces
        print("  ", end="")
        # Print right pyramid, only hashes
        print("#" * row)


if __name__ == "__main__":
    main()
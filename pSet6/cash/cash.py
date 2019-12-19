from cs50 import get_float


def main():
    change = get_change_owed("Changed owed: ")
    cents = dollars_to_cents(change)

    # Print the amount of cents as number of coins to return
    print(cents_to_coins(cents))


# Prompt user for an amount of change
def get_change_owed(prompt):
    while True:
        n = get_float(prompt)
        if n > 0:
            break
    return n


# Convert dollars to cents
def dollars_to_cents(amount):
    c = round(amount * 100)
    return c


# Always use the largest coin possible
# Keep track of coin used
def cents_to_coins(cents):
    # How many quarters in cents
    quarters = cents // 25
    # 1. Check how many quarters in cents
    # 2. How many dimes in the remaining amount of cents
    dimes = (cents % 25) // 10
    # 1. Check how many quarters & dimes in cents
    # 2.  How many nickels in the remaining amount of cents
    nickels = ((cents % 25) % 10) // 5
    # 1. Check how many quarters & dimes & nickels in cents
    # 2. The remainings are pennies  by default
    pennies = ((cents % 25) % 10) % 5

    # Return amount of coins in total
    return quarters + dimes + nickels + pennies


if __name__ == "__main__":
    main()
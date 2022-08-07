# Program to print multiplication table


def print_table(num, lim=10):
    for i in range(lim + 1):
        print(f"{num} * {i} = {num * i}")


def main():
    num = int(input("Enter a number: "))
    lim = int(input("Enter number of iterations of table: "))

    print_table(num, lim)


if __name__ == "__main__":
    main()

# Program to add two numbers


def main():
    a, b = map(int, input("Enter two numbers: ").split())
    print(f"{a} + {b} = {a + b}")


if __name__ == "__main__":
    main()

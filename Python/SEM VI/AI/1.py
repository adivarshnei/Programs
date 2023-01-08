# 1. Write a program to implement AND, OR and XOR gate

# Function to implement AND gate
def And(op1: bool, op2: bool) -> bool:
    return (op1 == True and op2 == True)


# Function to implement OR gate
def Or(op1: bool, op2: bool) -> bool:
    return (op1 == True or op2 == True)


# Function to implement XOR gate 
def Xor(op1: bool, op2: bool) -> bool:
    return (op1 != op2)


# Function to print table
def print_table(operations: "list[function]") -> None:
    for a in [True, False]:
        for b in [True, False]:
            print(f"\t{a}\t{b}\t", end = "")
            print(*[f"{operation(a, b)}\t" for operation in operations])


def main() -> None:
    print(f"All Tables\n\tx\ty\tx AND y\tx OR y\t x XOR y")
    print_table([And, Or, Xor])
    
    print("\n")

    op1: bool = bool(int(input("Enter first boolean operand (1/0): ")))
    op2: bool = bool(int(input("Enter second boolean operand (1/0): ")))

    print(f"{op1} AND {op2} = {And(op1, op2)}")
    print(f"{op1} OR  {op2} = {Or(op1, op2)}")
    print(f"{op1} XOR {op2} = {Xor(op1, op2)}")


if __name__ == "__main__":
    main()

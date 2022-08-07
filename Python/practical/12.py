# Program to implement calculator

while True:
    print(f"1. Addition")
    print(f"2. Subtraction")
    print(f"3. Multiplication")
    print(f"4. Division")
    choice = int(input("Enter Choice: "))

    if choice == 1:
        (op1, op2) = map(int, input("Enter operands: ").split())
    
        print(f"{op1} + {op2} = {op1 + op2}")
        
        break
    elif choice == 2:
        (op1, op2) = map(int, input("Enter operands: ").split())
    
        print(f"{op1} - {op2} = {op1 - op2}")    
        print(f"{op2} - {op1} = {op2 - op1}")
        
        break
    elif choice == 3:
        (op1, op2) = map(int, input("Enter operands: ").split())
        
        print(f"{op1} * {op2} = {op1 * op2}")
        
        break
    elif choice == 4:
        (op1, op2) = map(int, input("Enter operands: ").split())
        
        try:
            print(f"{op1} / {op2} = {op1 / op1}")
            print(f"{op2} / {op1} = {op2 / op1}")
            
        except:
            print(f"Values are invalid")
            
            continue
        
        break
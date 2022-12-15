import random

def gen_rand_arr(len):
    array = []

    for _ in range(len):
        array.append(random.randint(0, 100))

    return array

def main():
    len = int(input("Enter array length: "))

    array = gen_rand_arr(len)

    print(array)

    choice = int(input("1. Linear\n2. Binary\n3. Reset\n4. Exit\nEnter Choice: "))

    if choice == 1:
        pass
    elif choice == 2:
        pass
    elif choice == 3:
        pass
    elif choice == 4:
        pass
    else:
        pass

if __name__ == "__main__":
    main()
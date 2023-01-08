# 1-2. Write a program to perform basic set operations


def main():
    list_x = [1, 2, 1, 2, 1, 2, 1, 3, 4, 1, 5, 2, 6, 3, 25, 1, 5, 62, 34, 1]
    set_x = set(list_x)

    print(f"List from which set is created: {list_x}")
    print(f"Created set: {set_x}\n")

    set_x.add(5)
    print(f"Adding 5 to set: {set_x}")

    set_x.add(7)
    print(f"Adding 7 to set: {set_x}\n")

    set_x.update(set([1, 10]))
    print(f"Updating set using {{1, 10}}: {set_x}\n")

    set_x.discard(8)
    print(f"Discarding 8: {set_x}")

    set_x.discard(7)
    print(f"Discarding 7: {set_x}")


if __name__ == "__main__":
    main()

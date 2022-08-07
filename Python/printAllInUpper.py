fname = input(f"Enter a file name: ")

fhand = open(fname)

for line in fhand:
    print(line.upper())
    continue

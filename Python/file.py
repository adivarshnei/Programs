# %%

# Establishing File Handle, Returns Error if not found
fhand = open('file.txt')

# File Handle print
print(fhand)

# Traversing File and Reading Number of lines in file
count = 0
for line in fhand:
    count = count + 1
    print(f'Line Count: {count}')
    continue

# Returning to beginning of file
fhand = open('file.txt')

# Reading File Length
inp = fhand.read()
print(len(inp))
print(inp)

# Returning to beginning of file
fhand = open('file.txt')

# Reading File at specific point
for line in fhand:
    if line.startswith('hel'):
        print(line)
    
    continue

fhand = open('file.txt')

for line in fhand:
    if line.startswith('wro'):
        print(line)
     
    continue

fhand = open('file.txt')

for line in fhand: # Printing without extra newline
    line = line.rstrip()
    
    if line.startswith('hel'):
        print(line)
    
    continue

fhand = open('file.txt')

for line in fhand:
    line = line.rstrip()
    
    if not line.startswith('hel'):
        continue

    print(line)
    continue

fhand = open('file.txt')

for line in fhand:
    line = line.rstrip()
    
    if line.find('hel') == -1:
        continue
    
    print(line)
    continue

# User chooses file name
fname = input("Enter the file name: ")
fhand = open(fname)

count = 0

for line in fhand:
    if line.startswith("hel"):
        count += 1
    
    continue

print(f"There were {count} lines starting with 'hel' in {fname}")

# Error Protection
fname = input("Enter the file name: ")

try:
    fhand = open(fname)
    
except:
    print(f"File {fname} does not exist")
    # exit()
    
count = 0

for line in fhand:
    if line.startswith("hel"):
        count += 1
    
    continue

print(f"There were {count} lines starting with 'hel' in {fname}")

# Writing to files

fout = open("fileTest.txt", "w")
print(fout)

fout.write(f"Hello. This is written to a file using python3")

fout.close()
fout = open("fileTest.txt")

print(fout.read())

# Closing files

fout.close()
fhand.close()

# To get string representation of file contents (Handy for debugging)

fhand = open("file.txt")
for line in fhand:
    print (repr(line), end = '')
# %%

# Factor

# Creating a Factor
test_factor <- factor(c("CSE", "ECE", "EEE", "CSE", "EEE", "IOT", "IOT"))
print(test_factor)

# Checking if an Object is a Factor
v1 <- c(1, 2, 3, 1, 2, 3, 1, 2, 3)
f1 <- factor(v1)

print(is.factor(v1))
print(is.factor(f1))

# Accessing Factor Elements
print(f1[1])
print(f1[2])
print(f1)
print(f1[3])
print(f1[c(2, 3)])
print(f1[-2])

# Printing Class of a Factor
print(class(f1))

# Printing Levels of a Factor
print(levels(f1))

# Modifying a Factor
f2 <- f1
print(f2)

f2[2] <- 4 # is invalid, leaves <NA>
print(f2)

f2[2] <- 3
print(f2)

# Adding a Level to a Factor
levels(f2) <- c(levels(f2), "4")

f2[2] <- 4
print(f2)


# Q. Create a vector as input for student name list. Apply factor function.
# Print all elements of factor. Access the second element. Access the 8th and
# 9th elements. Print the values. Access all elements except the 6th. Print and
# access all elements using logical vectors.

names_v <- c(
  "Adersh",
  "Aditya",
  "Jaisurya",
  "Pragnya",
  "Nayan",
  "Shivansh",
  "Shruti",
  "Shubham",
  "Yash"
)

print(names_v)

names_f <- factor(names_v)

print(names_f)
print(names_f[2])
print(names_f[c(8, 9)])
print(names_f[-6])

print_vector <- c(
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  TRUE,
  TRUE,
  FALSE,
  TRUE,
  TRUE
)

print(names_f[print_vector])

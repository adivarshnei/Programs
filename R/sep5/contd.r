# Continued from September 1st on September 5th

test_array <- array(c(1:20), dim = c(4, 3, 2))

# Printing dimensional size
print(dim(test_array))

# Printing number of elements
print(length(test_array))

# Apply function
v1 <- c(1, 2, 3, 4)
v2 <- c(2, 3, 4, 5)

arr1_2 <- array(
  c(v1, v2),
  dim = c(3, 3),
  dimnames = list(
    c("r1", "r2", "r3"),
    c("c1", "c2", "c3")
  )
)

print(arr1_2)

r_sums <- apply(arr1_2, 1, sum)
c_sums <- apply(arr1_2, 2, sum)

rbind(cbind(arr1_2, Rtot = r_sums), Ctot = c(c_sums, sum(c_sums)))


# Factor

# Creating factors
test_factor <- factor(c("CSE", "ECE", "EEE", "CSE", "EEE", "IOT", "IOT"))
print(test_factor)

# Checking if object is factor
v1 <- c(1, 2, 3, 1, 2, 3, 1, 2, 3)
f1 <- factor(v1)

print(is.factor(v1))
print(is.factor(f1))

# Accessing factor elements
print(f1[1])
print(f1[2])
print(f1)
print(f1[3])
print(f1[c(2, 3)])
print(f1[-2])

# Class of Factor
print(class(f1))

# Levels of factor
print(levels(f1))

# Modification
f2 <- f1
print(f2)

f2[2] <- 4 # is invalid, leaves <NA>
print(f2)

f2[2] <- 3
print(f2)

# Adding level to add
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
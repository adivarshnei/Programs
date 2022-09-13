# Task 1: Declaration of single value
a <- 1.7
# We can also use 1.7 -> a
# We can also use a = 1.7
# We can also use assign("a", 1.7)
print("Declaration of Single Value")
cat("a = ", a)


# Task 2: Declaration of several values
a <- c(5, 10, 15, 20, 25, 30)
print("Declaration of Several Values")
cat("a = ", a)


# Task 3: Multiplication
b <- a * a
print("Multiplication")
cat(a, " * ", a, " = ", b)


# Task 4: Reciprocation
b <- 1 / a
print("Reciprocation")
cat("1 / ", a, " = ", b)


# Task 5: Subtraction
b <- a - 1
print("Subtraction")
cat(a, " - 1 = ", b)


# Task 6: Sequences
seq1 <- 2:10
seq2 <- seq(from = 0, to = 20, by = 5)
seq3 <- seq(0, 100, 20)

print("Sequences")
cat("2:10 = ", seq1, "\n")
cat("seq(from = 0, to = 20, by = 5) = ", seq2, "\n")
cat("seq(0, 100, 20) = ", seq3, "\n")


# Task 7: Trying incompatible dimensions
a1 <- c(1, 2, 5)
a2 <- c(1, 2, 3, 4)

cat("c(1, 2, 5) + c(1, 2, 3, 4) = ", (a1 + a2), "\n")

a1 <- c(1, 2, 3, 4, 5)
a2 <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

cat("c(1, 2, 3, 4, 5) + c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = ", (a1 + a2))


# Task 8: Removing of variables
ls()
rm(a1)
ls()


# Task 9: Vector of Strings
strings <- c("hello", "world")
cat("c(\"hello\", \"world\") = ", strings)


# Task 10:
# Creating Logical Value Sequences
logicals <- c(TRUE, FALSE, TRUE, FALSE, TRUE)
cat("c(TRUE, FALSE, TRUE, FALSE, TRUE) = ", logicals)


# Task 11: Sorting Vectors
strings <- c(
  "the",
  "quick",
  "brown",
  "fox",
  "jumped",
  "over",
  "the",
  "sleeping",
  "lazy",
  "dog"
)
sort(strings)

nums <- c(7, 3, 5, 7, 8, 2, 1, 25, 15, 72, 32)
sort(nums)


# Task 12: Accessing Vectors
a <- c("Dark", "was", "the", "Night,", "Cold", "was", "the", "Ground")
# Access by position via value
print(a[1])
# Access by position via sequence
print(a[c(1, 3)])
# Access using negative index
print(a[c(-2, -3)])
print(a[c(TRUE, FALSE, TRUE, FALSE, TRUE, FALSE, TRUE, FALSE)])

# Task 13: Changing Vector Items:
a[1] <- "123"
print(a)

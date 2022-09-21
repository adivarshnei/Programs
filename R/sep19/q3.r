# 3. Create two numeric vectors named x and y that are of equal length. Use
#    these vectors to answer the questions below.

cat(
  "1. Create two numeric vectors named x and y that are of equal length. Use",
  "these vectors to answer the questions below.\n"
)

x <- 5:10
y <- 10:15

cat("x =", x, "\n")
cat("y =", y, "\n")

# 1. How many numbers are there in the vector x?
cat("\n1. How many numbers are there in the vector x?\n")

cat("length(x) =", length(x), "\n")

# 2. How many numbers will x + y generate?
cat("\n2. How many numbers will x + y generate?\n")

cat("length(x + y) =", length(x + y), "\n")

# 3. What is the sum of all the values in x?
cat("\n3. What is the sum of all the values in x?\n")

cat("sum(x) = ", sum(x), "\n")

# 4. Assign x times 2 to a new vector named z
cat("\n4. Assign x times 2 to a new vector named z\n")

z <- x * 2
cat("z =", z, "\n")

# 5. How many numbers will z have, why?
cat("\n5. How many numbers will z have, why?\n")

cat("length(z) = ", length(z), "\n")
cat(
  "The length of z is identical to the length of z as the vector x is",
  "doubled elementwise\n"
)


# 6. Create a numeric vector with all integers from 5 to 107
cat("\n6. Create a numeric vector with all integers from 5 to 107\n")

new <- 5:107
cat("new =", new, "\n")

# 7. What will be the result of the following calculations?
# -> c(1, 3, 5) + c(2, 4, 6)
# -> c(1, 3, 5) + c(2, 4, 6, 8)
# -> c(1, 3) - c(2, 4, 6, 8)
# -> c(1, 3, 5) + c(2, 4, 6)
# -> c(1, 3, 5) + c(2, 4, 6, 8)
# -> c(1, 3) - c(2, 4, 6, 8)
cat("\n7. What will be the result of the following calculations?\n")
cat("-> c(1, 3, 5) + c(2, 4, 6) =", c(1, 3, 5) + c(2, 4, 6), "\n")
cat("-> c(1, 3, 5) + c(2, 4, 6, 8) =", c(1, 3, 5) + c(2, 4, 6, 8), "\n")
cat("-> c(1, 3) - c(2, 4, 6, 8)=", c(1, 3) - c(2, 4, 6, 8), "\n")
cat("-> c(1, 3, 5) + c(2, 4, 6)=", c(1, 3, 5) + c(2, 4, 6), "\n")
cat("-> c(1, 3, 5) + c(2, 4, 6, 8)=", c(1, 3, 5) + c(2, 4, 6, 8), "\n")
cat("-> c(1, 3) - c(2, 4, 6, 8)=", c(1, 3) - c(2, 4, 6, 8), "\n")

# Name:          Adersh Varshnei
# Date:          August 18th, 2022
# Enrollment No: A2305220129

# Q1: Assign a value to a vector with only one element (~ scalar)
a <- 5
print(a)

# Q2: Use assign("a", 1.7)
assign("a", 1.7)
print(a)

# Q3: Assign four values to a vector using the concatenate command c()
a <- c(2, 4, 6, 8)
print(a)

# Q4: Evaluate the square value of every element in the vector
print(a * a)

# Q5: Evaluate the inverse value of every element in the vector
print(1 / a)

# Q6 generate a sequence from n1 = 2 to n2 = 20 using n1:n2
n1 <- 2
n2 <- 20

seq1 <- n1:n2
print(seq1)

# Q7 generate an inverse sequence if n2 < n1
generate_sequence <- function(n1, n2) {
  if (n1 > n2) {
    return(n2:n1)
  } else if (n1 < n2) {
    return(n1:n2)
  }
}

cat("n1 = 5, n2 = 10: ", generate_sequence(5, 10), "\n")
cat("n1 = 6, n2 = 2: ", generate_sequence(6, 2), "\n")

# Q8 Try a <- 1:3; b <- rep(a, times=3); c <- rep(a, each=3)
a <- 1:3
b <- rep(a, times = 3)
c <- rep(a, each = 3)

cat("a = ", a, "\n")
cat("b = ", b, "\n")
cat("c = ", c, "\n")

# Q9 Try a + c, d <- c(10, 100), b + d
cat("a + c = ", a + c, "\n")

d <- c(10, 100)

cat("b + d = ", b + d, "\n")

# Q10 Generate a sequence, show its values on screen by assigning values from
# inequality b <- (a > 5). Also try a[b], a[a > 5]
b <- (a > 5)
print(b)

print(a[b])

print(a[a > 5])

# Q11 Generate a character vector, and show vector content
strings <- c("hello", "world")
cat("c(\"hello\", \"world\") = ", strings)

# Q12 Concatenate vectors after converting them into character vectors by
# using paste("Result is (",x,",",y,")", sep = "")
x <- c(5, 6)
y <- c(7, 8)

paste("Result is (", x, ", ", y, ")", sep = "")

# Task 1: Explore various data types in R.

x_numeric <- 10.5
cat(class(x_numeric), "is", x_numeric)
x_integer <- integer(10)
cat(class(x_integer), "is", x_integer)
x_logical <- 5 > 10
cat(class(x_logical), "is", x_logical)
x_complex <- 5 + 10i
cat(class(x_complex), "is", x_complex)
x_character <- "Hi!"
cat(class(x_character), "is", x_character)

# Task 2: Find data type of an object in R.
print(class(TRUE))
print(class(3L))
print(class(1 + 2i))
print(class("01-08-2022"))

# Task 3: Verification of Data Types in R.
x_test <- integer(1)

print(is.numeric(x_test))
print(is.integer(x_test))
print(is.logical(x_test))
print(is.complex(x_test))
print(is.character(x_test))


# Task 4: Changing Datatype of an object in R.
x_change <- 1.5

print(as.numeric(x_change))
print(as.integer(x_change))
print(as.logical(x_change))
print(as.complex(x_change))
print(as.character(x_change))


# Task 5: Exploring Operators in R.
cat("Arithmetic Operators:");
cat("\n6  +  5 =", as.character(6 + 5))
cat("\n6  -  5 =", as.character(6 - 5))
cat("\n6  *  5 =", as.character(6 * 5))
cat("\n6  /  5 =", as.character(6 / 5))
cat("\n6  %% 5 =", as.character(6 %% 5))
cat("\n6 %/% 5 =", as.character(6 %/% 5))
cat("\n6  ^  5 =", as.character(6^5))

cat("\nLogical Operators:")
cat("\n[TRUE, FALSE] | FALSE =", as.character(c(TRUE, FALSE) | FALSE))
cat("\n[TRUE, FALSE] & FALSE =", as.character(c(TRUE, FALSE) & FALSE))
cat(
  "\n[TRUE, FALSE] || [FALSE, TRUE] =",
  as.character(c(TRUE, FALSE) | c(FALSE, TRUE))
)
cat(
  "\n[TRUE, FALSE] && [FALSE, TRUE] =",
  as.character(c(TRUE, FALSE) | c(FALSE, TRUE))
)
cat("\n![TRUE, FALSE] =", as.character(!c(TRUE, FALSE)))

cat("\nRelational Operators:")
cat(
  "\n[2, 5, 10, 15]  > [2, 3, 14, 16] =",
  as.character(c(2, 5, 10, 15) > c(2, 3, 14, 16))
)
cat(
  "\n[2, 5, 10, 15]  < [2, 3, 14, 16] =",
  as.character(c(2, 5, 10, 15) < c(2, 3, 14, 16))
)
cat(
  "\n[2, 5, 10, 15] == [2, 3, 14, 16] =",
  as.character(c(2, 5, 10, 15) == c(2, 3, 14, 16))
)
cat(
  "\n[2, 5, 10, 15] <= [2, 3, 14, 16] =",
  as.character(c(2, 5, 10, 15) <= c(2, 3, 14, 16))
)
cat(
  "\n[2, 5, 10, 15] >= [2, 3, 14, 16] =",
  as.character(c(2, 5, 10, 15) >= c(2, 3, 14, 16))
)
cat(
  "\n[2, 5, 10, 15] != [2, 3, 14, 16] =",
  as.character(c(2, 5, 10, 15) != c(2, 3, 14, 16))
)

cat("\nAssignment Operators:")
a1 <- 3 + 5i
a2 <<- 3 + 5i
a3 = 3 + 5i
cat("\na1 <- 3 + 5i")
cat("\na1 =", a1)
cat("\na2 <<- 3 + 5i")
cat("\na2 =", a2)
cat("\na3 = 3 + 5i")
cat("\na3 =", a3)
3 + 5i -> a4
3 + 5i ->> a5
cat("\n3 + 5i -> a4")
cat("\na4 =", a4)
cat("\n3 + 5i ->> a5")
cat("\na5 =", a5)

cat("\nMiscellaneous Operators:")
cat("\n5:10 =", as.character(5:10))
cat("\n3 %in% [1, 2, 3, 4, 5]", as.character(3 %in% c(1:5)))

mat <- matrix(c(1:12), nrow = 4, ncol = 3, byrow = TRUE)
t <- mat %*% t(mat)
cat("\nmat <- matrix(c(1:12), nrow = 4, ncol = 3, byrow = TRUE)")
cat("\nmat %*% t(mat)=\n")
print(t)

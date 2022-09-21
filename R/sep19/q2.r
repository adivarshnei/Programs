# 2. Write commands in R to demonstrate the use of different data types in R.

cat("Numeric Data Type:\n")
x_numeric <- 10.5

cat("class(x_numeric) =", class(x_numeric), "\n")
cat("object.size(x_numeric) =", object.size(x_numeric), "\n")

cat("Integer Data Type:\n")
x_integer <- 10L

cat("class(x_integer) =", class(x_integer), "\n")
cat("object.size(x_integer) =", object.size(x_integer), "\n")

cat("Logical Data Type:\n")
x_logical <- 5 > 10

cat("class(x_logical) =", class(x_logical), "\n")
cat("object.size(x_logicalq =", object.size(x_logical), "\n")

cat("Complex Data Type:\n")
x_complex <- 5 + 10i

cat("class(x_complex) =", class(x_complex), "\n")
cat("object.size(x_complex) =", object.size(x_complex), "\n")

cat("Character Data Type:\n")
x_character <- "Hi!"

cat("class(x_character) =", class(x_character), "\n")
cat("object.size(x_character) =", object.size(x_character), "\n")

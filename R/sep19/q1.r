# 1. Write a R program to take input from the user (name and age) and display
#    the values. Also print the version of R installation

cat(
  "1. Write a R program to take input from the user (name and age) and",
  "display the values. Also print the version of R installation\n"
)

cat("Current R version:", R.version.string, "\n")

cat("Enter your name: ")
name <- readLines(con = "stdin", n = 1)

cat("Enter your age: ")
age <- as.integer(readLines(con = "stdin", n = 1))

cat("Name:", name, "\n")
cat("Age:", age, "\n")

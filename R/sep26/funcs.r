# Global Vars
test_str <- "GLOBAL"

# Adds two numbers
add <- function(a, b) {
  a + b
}

# Testing function arguments
arg_test_1 <- function(strng, numbr, compl) {
  cat("strng: ", strng, "\n")
  cat("numbr: ", numbr, "\n")
  cat("compl: ", compl, "\n")
}

# Testing default arguments
arg_test_2 <- function(strng = "NULL", numbr = 0, compl = 0 + 0i) {
  cat("strng: ", strng, "\n")
  cat("numbr: ", numbr, "\n")
  cat("compl: ", compl, "\n")
}

# Testing return values
ret_test <- function(var) {
  return(var * 2)
}

# Testing global variables
glob_test <- function() {
  print(test_str)

  test_str <- "LOCAL"
  # test_str <<- "LOCAL" can be used to change the value of the global variable
  # test_str

  print(test_str)
}

main <- function() {
  # 1: Create and call an addition function
  cat("5 + 10 = add(5, 10) =", add(a = 5, b = 10), "\n")

  # 2: Create a function with 3 arguments, call it with 3 arguments and 2
  # arguments successively
  arg_test_1(strng = "Hello World", numbr = 123L, compl = 12 + 3i)
  # arg_test_1("Hello World", 123L) Leads to an error, so it is commented out

  # 3: Create a function with default arguments, call it with and without
  # arguments successively
  arg_test_2()
  arg_test_2(compl = 12 + 3i)
  arg_test_2(numbr = 123L)
  arg_test_2(numbr = 123L, compl = 12 + 3i)
  arg_test_2(strng = "Hello World")
  arg_test_2(strng = "Hello World", compl = 12 + 3i)
  arg_test_2(strng = "Hello World", numbr = 123L)
  arg_test_2(strng = "Hello World", numbr = 123L, compl = 12 + 3i)

  # 4: Create and call a function that returns a value
  cat("5 * 2 = ret_test(5) =", ret_test(var = 5), "\n")

  # 5: Create and use global variables with a function
  glob_test()

  print(test_str)
}

main()

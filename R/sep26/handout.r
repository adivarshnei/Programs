add3 <- function(x) x + 3

add3(x = 5)
add3(-7)

#------------------------------------------------------------------------------#

manyCat <- function(word, n) {
  for (i in 1:n) {
    cat(word, "")
  }

  cat("\n")
}

manyCat(word = "Hello", n = 4)
manyCat(word = "Hello", 4)
manyCat("Hello", n = 4)
manyCat("Hello", 4)
manyCat(n = 4, word = "Hello")

#------------------------------------------------------------------------------#

# What, if anything, does the following function return?
f <- function(n) {
  cat("We have ", n, " dogs.\n", sep = "")
}

f(5)

# It returns the statement "We have n dogs", where n is the argument given to
# the function

#------------------------------------------------------------------------------#

# What, if anything, does the following function return?
g <- function(n) {
  n + 3
  "Hello"
}

g(5)

# It returns the result of the last statement executed, i.e., "Hello"

#------------------------------------------------------------------------------#

# What, if anything, does the following function return?
h <- function(n) {
  "Hello"
  n + 3
}

h(5)

# It returns the result of the last statement executed, i.e., n + 3, where n is
# the argument given to the function

#------------------------------------------------------------------------------#

inhabitants <- c("Munchkin", "Winkie", "Quadling", "Gillikin")
favColor <- c("blue", "yellow", "red", "purple")
names(favColor) <- inhabitants

favColorReport <- function(inhabitant = inhabitants) {
  x <- match.arg(inhabitant)
  cat(favColor[x], "\n")
}

favColorReport("Winkie")
favColorReport("Quadling")
# favColorReport("w") Commented due to error
favColorReport()

#------------------------------------------------------------------------------#

# Write a function called addSix() that adds six to any number that is given.
# The function should have a single parameter named x, and the default value of
# x should be 5.

addSix <- function(x = 5) {
  x + 6
}

addSix

for (i in 1:5){
  print(addSix(i))
}

#------------------------------------------------------------------------------#

# Tin Man wants to write a function called addTenAndSquare() that takes any
# given number, adds ten to it and then squares the result. For example, given 5
# the function will return (5 + 10) ^ 2 = 225. He decides that input value shall
# be called n and that the default value of n shall be 4.

addTenAndSquare <- function(n = 4) {
  return((n + 10) ^ 2)
}

addTenAndSquare

print(addTenAndSquare(5))

#------------------------------------------------------------------------------#

a <- 10
b <- 4

f <- function(x, y) {
  a <- 5
  print(ls())
  
  cat("a is ", a, "\n", 
      "b is ", b, "\n",
      "x is ", x, "\n",
      "y is ", y, "\n", sep = "");
  
}

f(1, 2)

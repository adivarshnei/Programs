# Task 1: Explore commands related to viewing datasets in R
library(datasets)

datasets::BOD

BOD <- datasets::BOD

View(BOD)

nrow(BOD)


# Task 2: Print the head of a dataset in R
head(BOD, n = 3)

# Task 3: Explore various commands related to datasets and lists in R.
# a)
summary(mtcars$mpg)

# b)
summary(c(3, 2, 1, 2, 4, 6))

# c)
str(c(1, 2, 3, 4))

# d)
str(c("Mon", "Tue", "Wed", "Thurs"))

# e)
head(c("Mon", "Tue", "Wed", "Thurs"), 2)

# f)
tail(c("Mon", "Tue", "Wed", "Thurs"), 2)

# g)
class(76.25L)

# Task 4: Explore user-defined functions in R.
f <- function(x) {
    g <- function(y) {
        y + z
    }

    z <- 4
    x + g(x)
}

f(5)

# Task 5: Explore various assignment operators in R
n <- 15

n

5 -> n

n

x <- 1

X <- 10

x

X

# Task 6: Displaying list of created objects in R.
name <- "Carmen" ; n1 <- 10 ; n2 <- 100 ; m <- 0.5

ls()

# Task 7: Displaying help in R.

?
*

?? otuput

?*

help("*")

?? output

? lm

# Task 8: Exploring various commands related to objects in R

x <- 1

mode(x)

length(x)

A <- "Gomphotherium" ; compar <- TRUE ; z <- 1i

mode(A) ; mode(compar) ; mode(z)

x = 5

5 * x -> x

x

mydata <- read.table("data.dat", sep = ',')

mydata

1:10

-3:4

9:5

seq(from = 2, to = 6, by = 0.4)

seq(from = -1, to = 1, by = 6)

rep(5, 3)

rep(2:5, each = 3)

# Name: Adersh Varshnei
# Section: 5CSE2-Y
# Course: CSE437 (R Programming)
# Date: September 22nd, 2022
# Topic: Handout on Loops in R

# Q1. Find the output of below statements
vec.a <- c(1, 2, 3, 4)
vec.a * 2

# Q2. Execute the below code
v <- rep(0, times = 4)

for (i in vec.a) {
  v[i] <- vec.a[i] * 2
}

vec.a
v

# Q3. Write a while loop that prints out standard random normal numbers (use
#     rnorm()) but stops (breaks) if you get a number bigger than 1.
while ((x <- rnorm(1)) < 1) {
  cat("var: ", x, "\n")
}

# Q4. Find the output of the below statements
for (y in 1:10) {
  print(paste(3, "*", y, "=", 3 * y))
}

# Q5. Match Output
for (row in 1:3) {
  for (col in 1:4) {
    print(paste(row, col))
  }
}

# Q6. Print reverse of the output of Q5.
for (row in 3:1) {
  for (col in 4:1) {
    print(paste(row, col))
  }
}

# Q7. Get all even numbers between 1 to 20 using next statement
for (i in 1:20) {
  if (i %% 2 != 0) {
    next
  }

  cat(i, "\t")
}

# Q8. Print your name 10 times
i <- 1
name <- readline(prompt = "Enter name: ")

while (i <= 10) {
  cat(i, ":", name, "\n")
  i <- i + 1
}

# Q9. Print counting from 45 to 35
for (i in 45:35) {
  cat(i, "\t")
}
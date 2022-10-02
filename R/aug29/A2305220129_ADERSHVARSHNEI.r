# 1) Create Blank matrix with r=5,c=6)
m1 <- matrix(, nrow = 5, ncol = 6)

# 2) Write a R program to create a matrix taking a given vector of numbers as
# input. Display the matrix.
num_vector <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)
m2 <- matrix(num_vector, nrow = 3, ncol = 3)
print(m2)

# 3) What this code doing?

row_names <- c("row1", "row2", "row3", "row4")
col_names <- c("col1", "col2", "col3", "col4")
M <- matrix(
  c(1:16),
  nrow = 4,
  byrow = TRUE,
  dimnames =
    list(row_names, col_names)
)
print("Original Matrix:")
print(M)
result <- M[M[, 3] > 7, ]
print("New submatrix:")
print(result)

# This code creates a 4x4 matrix containing numbers from 1 to 16 arranged by
# row. (M[, 3] > 7) checks the 3rd col in the matrix, and compares each element
# with 7. (3, 7, 11, 15) > 7 evaluates to (FALSE, FALSE, TRUE, TRUE). Therefore,
# the last two rows of M are stored in result, which is printed.

# 4) Use length function
length(m1)

# 5) Create M1 and M2 use rbind and cbind to combine M1 and M2 # print
M1 <- matrix(c(1:9), nrow = 3, ncol = 3)
M2 <- matrix(c(10:18), nrow = 3, ncol = 3)

M1_2_rbind <- rbind(M1, M2)
M1_2_cbind <- cbind(M1, M2)

print(M1_2_rbind)
print(M1_2_cbind)

# 6) Perform Basic Computations on M1 and M2
# Use cat("Result of Computation")
M1_plus_M2 <- M1 + M2
M1_minus_M2 <- M1 - M2
M1_times_M2 <- M1 * M2
M1_div_M2 <- M1 / M2

cat(M1, " + ", M2, " = ", M1_plus_M2, "\n")
cat(M1, " - ", M2, " = ", M1_minus_M2, "\n")
cat(M1, " * ", M2, " = ", M1_times_M2, "\n")
cat(M1, " / ", M2, " = ", M1_div_M2, "\n")

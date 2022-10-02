# Creating an array
test_array <- array(c(1:20))

print(test_array)

# Creating a Multidimensional Array
test_array_mul_dim <- array(test_array, dim = c(4, 3, 2))

print(test_array_mul_dim)

# Giving Names to Array Dimensions
r_names <- c("R1", "R2", "R3", "R4")
c_names <- c("C1", "C2", "C3")
m_names <- c("M1", "M2")

test_array_names <- array(
  test_array,
  dim = c(4, 3, 2),
  dimnames = list(r_names, c_names, m_names)
)

print(test_array_names)

# Continued from September 1st on September 5th

# Printing Dimensional Size of an Array
print(dim(test_array_mul_dim))

# Printing Number of Elements in Array
print(length(test_array_mul_dim))

# Using Apply Function to Add Rows and Columns
v1 <- c(1, 2, 3, 4)
v2 <- c(2, 3, 4, 5)

arr1_2 <- array(
  c(v1, v2),
  dim = c(3, 3),
  dimnames = list(
    c("r1", "r2", "r3"),
    c("c1", "c2", "c3")
  )
)

print(arr1_2)

r_sums <- apply(arr1_2, 1, sum)
c_sums <- apply(arr1_2, 2, sum)

rbind(cbind(arr1_2, R_tot = r_sums), C_tot = c(c_sums, sum(c_sums)))



# Creating an array
test_array <- array(c(1:20))

print(test_array)

# Multidimensional Arrays
test_array_mul_dim <- array(test_array, dim = c(4, 3, 2))

print(test_array_mul_dim)

# Naming Columns and Rows of an array
r_names <- c("r1", "r2", "r3", "r4")
c_names <- c("c1", "c2", "c3")
m_names <- c("m1", "m2")

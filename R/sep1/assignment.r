r.names <- c("Row 1", "Row 2", "Row 3")
c.names <- c("Column 1", "Column 2", "Column 3")
m.names <- c("Matrix 1", "Matrix 2")

v1 <- c(1, 2, 3, 4)
v2 <- c(2, 3, 4, 5)

result <- array(
  c(v1, v2),
  dim = c(3, 3, 2), dimnames = list(r.names, c.names, m.names)
)
print(result)

# ---------------------------------------------------------------------------- #

ta <- c(1:20)
ma <- array(ta, dim = c(4, 3, 2))

ma[2, 3, 2]

# ---------------------------------------------------------------------------- #

test <- array(c(1:20))

ma <- array(test, dim = c(4, 3, 2))

print(ma)

ma[c(1), , 1]

# ---------------------------------------------------------------------------- #

ma[, c(1), 1]

# ---------------------------------------------------------------------------- #

print(result)

print(5 %in% result)
print(6 %in% result)

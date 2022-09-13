# Creating a matrix
m1 <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 6, ncol = 1)
m2 <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 3, ncol = 2)
m3 <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 2, ncol = 3)
m4 <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 1, ncol = 6)
m5 <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 3, ncol = 4)
m6 <- matrix(c(2:5), nrow = 2, ncol = 2)
m7 <- matrix(c(2:5), nrow = 4, ncol = 4)

print(m1)
print(m2)
print(m3)
print(m4)
print(m5)
print(m6)
print(m7)

# Arranging elements by row or column
m1 <- matrix(c(1:9), nrow = 3, ncol = 3, byrow = TRUE)
m2 <- matrix(c(1:9), nrow = 3, ncol = 3, byrow = FALSE)

print(m1)
print(m2)

# Dimension Names
row_names <- c("r1", "r2", "r3")
col_names <- c("c1", "c2", "c3")

m1 <- matrix(c(1:9), nrow = 3, ncol = 3, dimnames = list(row_names, col_names))

print(m1)

# Accessing
print(m1[3, 1])
print(m1[2, 3])
print(m1[2, seq_len(dim(m1)[2])])
print(m1[seq_len(dim(m1)[1]), 3])
print(m1[c(1, 2), ])
print(m1[, c(1, 2)])

# Adding rows
m1_r <- rbind(m1, c(10, 11, 12))
m1_c <- cbind(m1, c(10, 11, 12))

dimnames(m1_r) <- list(c(row_names, "r4"), col_names)
dimnames(m1_c) <- list(row_names, c(col_names, "c4"))

print(m1_r)
print(m1_c)

# Removing Elements
m1_rem_row <- m1[c(-2), ]
m1_rem_col <- m1[, c(-2)]

print(m1_rem_row)
print(m1_rem_col)

for (i in 1:10) {
    if (i > 5) {
        break
    }

    print(i)
}

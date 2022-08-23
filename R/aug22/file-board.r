# Creating a list
test_list <- list("string", 123, 12 + 2i, TRUE)

print(test_list)
cat("\n\n\n")

# Accessing List Elements
print(test_list[1])
print(test_list[2])
print(test_list[3])
print(test_list[4])

cat("\n\n\n")

# Updating List Items
test_list[1] <- "Dark"
test_list[2] <- "was"
test_list[3] <- "the"
test_list[4] <- "Night"

print(test_list)

cat("\n\n\n")

# Finding list length
print(length(test_list))

cat("\n\n\n")

# Finding existence of element in list
print("dark" %in% test_list)
print("Dark" %in% test_list)

cat("\n\n\n")

# Adding Items to List
test_list <- append(test_list, "Cold")
test_list <- append(test_list, "was")
test_list <- append(test_list, "the")
test_list <- append(test_list, "Ground")

print(test_list)

cat("\n\n\n")

# Trying negative indices
print(test_list[-2])

cat("\n\n\n")

# Removing Elements
print(test_list)

test_list[length(test_list)] <- NULL

print(test_list)

cat("\n\n\n")

# Second List Creation, Giving names to elements
test_list2 <- list("Hello", c(1, 2, 3, 4, 5), TRUE)
print(test_list2)

cat("\n\n\n")

names(test_list2) <- c("e1", "e2", "e3")
print(test_list2$e1)

cat("\n\n\n")

# Create a list with a two strings and a five element vector. Name them and
# access them by name
test_list3 <- list("Hello", "World", c(1, 2, 3, 4, 5))

names(test_list3) <- c("str1", "str2", "vec")

print(test_list3$vec[2])

cat("\n\n\n")

# Create two elements, one with 5, one with 7 and merge these lists via c()
test_list4 <- list(1, 2, 3, 4, 5)
test_list5 <- list("un", "deux", "trois", "quatre", "cinq", "six", "sept")

test_list6 <- c(test_list4, test_list5)

print(test_list6)

cat("\n\n\n")

# Create a list of 10 elements, each element being the name of a car. Access
# the list elements using range
test_list7 <- list(
  "Corvette Stingray", "GT350", "GT500", "300 SL", "Challenger R/T Hemi",
  "Road Runner", "250 GTO", "Cobra", "GT40", "Daytona"
)

test_list7[3:9]
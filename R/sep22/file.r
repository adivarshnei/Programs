# if else
#
# Syntax:
#   if (condition) {
#     statements
#   } else if (condition) {
#     statements
#   } else if (condition){
#     .
#     .
#     .
#   } else {
#     statements
#   }

if ((5 > 6) == TRUE) {
  cat("5 > 6\n")
} else if ((5 == 6) == TRUE) {
  cat("5 = 6\n")
} else {
  cat("5 < 6\n")
}

#
# Loops:
#   repeat
#   while
#   for
# Loop Control Statements:
#   break
#   next
#
# for loop
#
# Syntax:
#   for (value in vector) {
#     statements
#   }

for (i in 1:5) {
  cat(i, "\t")
}

cat("\n")

car_list <- list(
  "Ford GT40",
  "Plymouth Superbird",
  "Shelby GT500",
  "Chevrolet Special Deluxe",
  "Mercedes 300SL"
)

for (car in car_list) {
  cat(car, "\t")
}

cat("\n")

for (i in 1:20) {
  if (i %% 5 != 0) {
    next
  }

  cat(i, "\t")
}

cat("\n")

i <- 10
repeat {
  if (i < 5) {
    break
  } else {
    cat(i, "\t")
    i <- i - 1
  }
}

cat("\n")

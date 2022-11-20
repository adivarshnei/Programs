# Q1. Create 2 vectors and plot x against y

x <- floor(abs(rnorm(50) * 100))
y <- floor(abs(rnorm(50) * 100))

plot(
  y ~ x,
  xlab = "Random x",
  ylab = "Random y",
  main = "Q1.",
  col = "green"
)

#------------------------------------------------------------------------------#
# Q2. Create a plot using one vector only

plot(
  x,
  xlab = "index",
  ylab = "random x",
  main = "Q2.",
  col = "green"
)

#------------------------------------------------------------------------------#
# Q3. Try

plot(
  x,
  y,
  col = "red",
  pch = 2,
  type = "b",
  main = "a pretty scatter plot"
)

plot(
  x,
  y,
  col = 1:10,
  pch = 1:10,
  cex = 1:10,
  type = "b",
  main = "an even prettier scatter plot"
)

#------------------------------------------------------------------------------#
# Q4. Try

for (i in 0:25) {
  plot(
    x,
    pch = i,
    main = paste("Q4. Plot ", i)
  )
}

points <- c("*", ".", "o", "O", "0", "+", "-", "|", "%", "#")

for (i in 1:length(points)) {
  plot(
    x,
    pch = points[i],
    main = paste("Q4. Plot", (i + 25))
  )
}

#------------------------------------------------------------------------------#
# Q5. Display the 8-color palette, 657-colors, find colors, change palette and
# then change back to default

# print(palette())
# print(colors())

grep("green", colors(), value = TRUE)

palette(grep("green", colors(), value = TRUE))
plot(x, y, col = rep(1:10, each = 10), pch = 19, main = "Q5. Green Palette")

palette("default")
plot(x, y, col = rep(1:10, each = 10), pch = 19, main = "Q5. Default Palette")

#------------------------------------------------------------------------------#
# Q6. Create a bar plot

x <- rep(c("PhDstudent", "Postdoc", "Technician", "PI"), c(8, 10, 5, 2))

mytable <- table(x)

barplot(mytable, main = "Q6.")

#------------------------------------------------------------------------------#
# Q7. Customize the above barplot

palette(grep("seagreen2", colors(), value = TRUE))
barplot(
  mytable,
  col = 1:4,
  main = "Q7.",
  las = 2,
  xlab = "Post",
  ylab = "Count"
)

#------------------------------------------------------------------------------#
# Q8. Try

xfact <- factor(
  x,
  levels = c("PhDstudent", "Postdoc", "Technician", "PI"),
  ordered = TRUE
)

xfacttable <- table(xfact)

barplot(
  xfacttable,
  col = 1:4,
  main = "Q8.",
  las = 2,
  xlab = "Post",
  ylab = "Count"
)

print(x)

#------------------------------------------------------------------------------#
# Q9. Create a matrix of number of types of employees per research program

barmat <- matrix(xfacttable, nrow = 4, dimnames = list(levels(xfact)))
mycolors <- sample(colors(), 4)

barplot(
  barmat,
  col = mycolors,
  ylim = c(0, 50),
  main = "Q9. stacked barplot"
)

legend(
  "topleft",
  legend = levels(xfact),
  fill = mycolors
)

#------------------------------------------------------------------------------#
# Q10. Pie Chart

variable <- rep(
  c("PhDstudent", "Postdoc", "Technician", "PI"),
  c(10, 15, 6, 19)
)

myvariable <- table(variable)

pie(
  myvariable,
  main = "Q10. pie chart",
  col = c("lightblue", "lightgreen", "salmon", "maroon")
)

#------------------------------------------------------------------------------#
# Q11. Boxplot

x <- matrix(rnorm(1000), ncol = 4)

boxplot(x, main = "Q11.")
boxplot(
  x,
  main = "Q11.",
  xlab = "x",
  ylab = "y",
  at = c(1, 2, 4, 5)
)
abline(
  h = 0,
  col = "black",
  lwd = 0.5,
  lty = 3
)

#------------------------------------------------------------------------------#
# Q12. Histogram
randnums <- rnorm(200)

hist(
  randnums,
  border="blue",
  breaks=50,
  main="Q12. Histogram",
  xlab=""
)

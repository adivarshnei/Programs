# To load graphics package
library("graphics")

# To load datasets package
library("datasets")

# To load mtcars dataset
data(mtcars)

# To analyse the structure of the dataset
str(mtcars)

palette(grep("seagreen2", colors(), value = TRUE))

# Q1. We can obeserve that hp and mpg have a negative correlation, which means
# that horsepower increases as miles per gallon decreases. How?
plot(
  x = mtcars$hp,
  y = mtcars$mpg,
  col = 10,
  xlab = "HP",
  ylab = "MPG",
  main = "HP vs MPG"
)

# Cars with MPG between 10 and 16
barplot(
  mtcars$mpg[mtcars$mpg >= 10 & mtcars$mpg <= 15],
  names.arg = which(mtcars$mpg >= 10 & mtcars$mpg <= 15),
  col = 1:6,
  main = "Cars with 10 <= mpg <= 15",
  xlab = "Car index",
  ylab = "MPG"
)

# Boxplots for disp and hp
temp <- data.frame(disp = mtcars$disp, hp = mtcars$hp)
boxplot(temp, col = 1:2)

# Draw a scatter plot between cyl and vs
library("ggplot2")

mtcars$am <- as.factor(mtcars$am)
mtcars$cyl <- as.factor(mtcars$cyl)
mtcars$vs <- as.factor(mtcars$vs)

ggplot(data = mtcars, mapping = aes(x = cyl, y = vs)) +
  geom_point()
ggplot(data = mtcars, mapping = aes(x = cyl, y = vs)) +
  geom_point() +
  geom_jitter(width = 0.1, height = 0.1)


# Scatterplot between cyl and vs using am
ggplot(data = mtcars, mapping = aes(x = cyl, y = vs, color = am)) +
  geom_point() +
  geom_jitter(width = 0.1, height = 0.1, alpha = 0.5)

# Mosaicplot
data(HairEyeColor)

mosaicplot(
  x = HairEyeColor,
  color = 1:6
)

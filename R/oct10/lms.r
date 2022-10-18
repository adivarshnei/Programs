# Loading Datasets
data(mtcars)

data(airquality)

data(cars)

# Creating a barplot visualisation
barplot(table(mtcars$gear))

# Creating a barplot visualisation with additional arguments
barplot(
  table(mtcars$gear),
  xlab = "Number of Gears",
  ylab = "Frequencies",
  main = "Cars with number of Gears",
  col = "navyblue",
  border = "red"
)

# Creating a histogram visualisation
hist(airquality$Temp)

# Creating a histogram visualisation with additional arguments
hist(
  x = airquality$Temp,
  xlab = "Temp in Fahrenheit",
  ylab = "Frequency Numbers",
  main = "Histogram for Temp from air quality data",
  breaks = 10,
  col = "lightseagreen",
  border = "red"
)

# Creating a boxplot visualisation
boxplot(airquality$Wind)

# Creating a boxplot for one variable vs other
boxplot(Wind ~ Month, data = airquality)

# Creating a boxplot for one variable vs other
boxplot(
  Wind ~ Month,
  data = airquality,
  xlab = "Months",
  ylab = "Mile/hr. Avg. Wind Speed",
  main = "Months vs Mile/hr. Avg. Wind Speed",
  pch = 20,
  cex = 2,
  col = "turquoise",
  border = "red"
)

# Creating a scatterplot
plot(speed ~ dist, data = cars)

# Creating a customized scatterplot
plot(
  speed ~ dist,
  data = cars,
  xlab = "distance in ft",
  ylab = "Speed in Miles/hr",
  main = "Scatterplot of distance vs speed of cars",
  pch = 20,
  cex = 2,
  col = "blue"
)
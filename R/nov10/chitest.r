cars93 <- MASS::Cars93

print(str(cars93))

car_data <- table(cars93$Cylinders, cars93$Type)
print(car_data)

print(chisq.test(car_data, simulate.p.value = TRUE))

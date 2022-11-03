library(package = datasets)

dataset <- data.frame(datasets::Titanic)

cat("\nComplete Dataset:\n")
print(x = dataset)
# View(dataset) Laggy

cat("\nDataset head:\n")
print(x = head(x = dataset, 3))

cat("\nDataset tail:\n")
print(x = tail(x = dataset, 3))

cat("\nDataset colnames:\n")
print(x = names(x = dataset))

cat("\nDataset data type:\n")
print(x = class(x = dataset))
cat("Class: ", class(dataset$`Class`[0]))
cat("\nSex: ", class(dataset$`Sex`[0]))
cat("\nAge: ", class(dataset$`Age`[0]))
cat("\nSurvived: ", class(dataset$`Survived`[0]))
cat("\nFreq: ", class(dataset$`Freq`[0]), "\n")

cat("\nStructure of dataset:\n")
print(x = str(dataset))

cat("\nSummary of dataset:\n")
print(x = summary(dataset))

palette(grep(pattern = "seagreen2", x = colors(), value = TRUE))

# 1. What was the survival rate?
survivals <- aggregate(
  x = dataset$`Freq`,
  by = list(Survived = dataset$`Survived`),
  FUN = sum
)

rownames(survivals) <- survivals$`Survived`

barplot(
  height = t(survivals["x"]),
  xlab = "Survival Status",
  ylab = "Number of Passengers",
  main = "Survival Status of the Passengers",
  col = c(5)
)

# 2. How many people did survive?
barplot(
  height = t(survivals["x"][survivals["Survived"] == "Yes"]),
  xlab = "Survived Passengers",
  ylab = "Number of Passengers",
  main = "Surviving Passengers",
  col = c(10)
)

# 3. What was the survival rate based on gender?
survivals <- aggregate(
  x = dataset$`Freq`,
  by = list(Survived = dataset$`Survived`, Gender = dataset$`Sex`),
  FUN = sum
)

survival_table <- xtabs(x ~ Survived + Gender, survivals)
rownames(survival_table) <- paste("Survived:", rownames(survival_table))

barplot(
  height = survival_table,
  xlab = "Survival Status",
  main = "Survival Status of the Passengers",
  col = c(5, 6),
  horiz = TRUE,
  cex.names = 0.75,
  beside = TRUE,
  legend = rownames(survival_table)
)

# 4. What was the survival rate based on class?
survivals <- aggregate(
  x = dataset$`Freq`,
  by = list(Survived = dataset$`Survived`, Class = dataset$`Class`),
  FUN = sum
)

survival_table <- xtabs(x ~ Survived + Class, survivals)
rownames(survival_table) <- paste("Survived:", rownames(survival_table))

barplot(
  height = survival_table,
  xlab = "Survival Status",
  main = "Survival Status of the Passengers",
  col = c(5, 6),
  horiz = TRUE,
  cex.names = 0.75,
  beside = TRUE,
  legend = rownames(survival_table)
)

# 5. What was the survival rate based on age?
survivals <- aggregate(
  x = dataset$`Freq`,
  by = list(Survived = dataset$`Survived`, Age = dataset$`Age`),
  FUN = sum
)

survival_table <- xtabs(x ~ Survived + Age, survivals)
rownames(survival_table) <- paste("Survived:", rownames(survival_table))

barplot(
  height = survival_table,
  xlab = "Survival Status",
  main = "Survival Status of the Passengers",
  col = c(5, 6),
  horiz = TRUE,
  cex.names = 0.75,
  beside = TRUE,
  legend = rownames(survival_table)
)

# 6. What was the survival rate based on class, age and gender?
# survivals <- aggregate(
#   x = dataset$`Freq`,
#   by = list(
#     Survived = dataset$`Survived`,
#     Age = dataset$`Age`,
#     Class = dataset$`Class`,
#     Gender = dataset$`Sex`
#   ),
#   FUN = sum
# )

# survival_table <- xtabs(x ~ Survived + Age + Class + Gender, survivals)
# rownames(survival_table) <- paste("Survived:", rownames(survival_table))

# print(survival_table)

# barplot(
#   height = as.matrix(survival_table),
#   xlab = "Survival Status",
#   main = "Survival Status of the Passengers",
#   col = c(5, 6),
#   horiz = TRUE,
#   cex.names = 0.75,
#   beside = TRUE,
#   legend = rownames(survival_table)
# )

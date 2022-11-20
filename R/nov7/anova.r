mtcars <- datasets::mtcars

print("One way ANOVA")

boxplot(mtcars$disp ~ factor(mtcars$gear), xlab = "gear", ylab = "disp")

mtcars_aov <- aov(mtcars$disp ~ factor(mtcars$gear))
print(summary(mtcars_aov))

print("Two way ANOVA")
boxplot(
    formula = mtcars$disp ~ mtcars$gear,
    subset = (mtcars$am == 0),
    xlab = "gear",
    ylab = "disp",
    main = "Automatic"
)
boxplot(
    formula = mtcars$disp ~ mtcars$gear,
    subset = (mtcars$am == 1),
    xlab = "gear",
    ylab = "disp",
    main = "Manual"
)

mtcars_aov2 <- aov(mtcars$disp ~ factor(mtcars$gear) * factor(mtcars$am))
print(summary(mtcars_aov2))

print("Three way ANOVA")
# boxplot(
#     formula = mtcars$disp ~ mtcars$gear,
#     subset = (mtcars$am == 0),
#     xlab = "gear",
#     ylab = "disp",
#     main = "Automatic"
# )
# boxplot(
#     formula = mtcars$disp ~ mtcars$gear,
#     subset = (mtcars$am == 1),
#     xlab = "gear",
#     ylab = "disp",
#     main = "Manual"
# )


mtcars_aov2 <- aov(
    mtcars$disp ~ factor(mtcars$gear) * factor(mtcars$am) * factor(mtcars$carb)
)
print(summary(mtcars_aov2))

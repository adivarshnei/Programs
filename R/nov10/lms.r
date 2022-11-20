iris <- datasets::iris
print(head(iris))

random <- sample(seq_len(nrow(iris)), 0.9 * nrow(iris))

normalize <- function(x) {
    (x - min(x)) / (max(x) - min(x))
}

iris_norm <- as.data.frame(lapply(iris[, 1:4], normalize))

print(summary(iris_norm))

iris_train <- iris_norm[random, ]
iris_test <- iris_norm[-random, ]
iris_target_category <- iris[random, 5]
iris_test_category <- iris[-random, 5]

library("class")

pr <- knn(
    train = iris_train,
    test = iris_test,
    cl = iris_target_category,
    k = 13
)

tab <- table(pr, iris_test_category)
print(tab)

accuracy <- function(x) {
    sum(diag(x) / (sum(rowSums(x)))) * 100
}

accuracy(tab)

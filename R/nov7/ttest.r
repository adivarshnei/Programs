# if we want to test that the volume of a shipment is less than the usual,
# where the mean is 37000 cu. ft., you will run one sample T-test and don't
# know the populations, std. dev.

n_val <- 500000
mean_val <- 37000
sd_val <- 25000

set.seed(0)
ship_v <- c(rnorm(n = n_val, mean = mean_val, sd = sd_val))

t_test <- t.test(ship_v, mu = mean_val)

print(t_test)

# Paired t-test
# two variables of interest
# suppose we are working at a large health clinic and we are testing a new
# medicine, whose work is to reduce hypertension. we find 13000 individuals with
# high blood pressure. mean = 150, sd = 10. we provided that new medicine to
# them for a month and then observed their blood pressure again. we find that
# mean blood pressure has decreased to 144, with a standard deviation of 9.

n_samples <- 500000
mean_avant <- 150
sd_avant <- 10
mean_apres <- 144
sd_apres <- 9

set.seed(10000)
avant <- c(rnorm(n = n_samples, mean = mean_avant, sd = sd_avant))
apres <- c(rnorm(n = n_samples, mean = mean_apres, sd = sd_apres))

t_test <- t.test(avant, apres, paired = TRUE)
print(t_test)

# anova test
# used to estimate how quantitative dependent data or variable is influenced by
# independent data or variables, according to the levels of one or more
# categorial independent variables.
# types: we can compare independent groups using one way, two way and three way
# anova.
# one way anova is extension of independent sample t-test for comparing the
# means in a situation where there are two independent groups.
# two way anova compares two groups, evaluating the effect of two different
# grouping variables on a continuous outcome variable
# three way anova evaluates the effect of three different grouping variables on
# a continuous outcome variable
# assumptions: each subject should belong to only one group, there is no
# relation between the observations in each group.



# install.packages("tidyverse")
# install.packages("ggpubr")
# install.packages("rstatix")

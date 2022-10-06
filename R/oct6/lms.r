library(package = "R6")

student <- R6Class(
  classname = "student",
  public = list(
    initialize = function(name = NA, age = NA, hair_color = NA) {
      private$name <- name
      private$age <- age
      private$hair_color <- hair_color
    }
  ),
  private = list(
    name = NULL,
    age = NULL,
    hair_color = NULL
  )
)

s1 <- student$new(name = "A", age = 13, hair_color = "XYZ")
print(s1)
print(s1$age)

student <- R6Class(
  classname = "student",
  public = list(
    initialize = function(name = NA, age = NA, hair_color = NA) {
      private$name <- name
      private$age <- age
      private$hair_color <- hair_color
      self$say_hello()
    },
    say_hello = function() {
      cat(private$name, " ABC!\n", sep = "")
    },
    show = function() {
      cat("STUDENT:\n")
      cat("\tName: ", private$name, "\n", sep = "")
      cat(
        "\tAge: ",
        private$age,
        " or ",
        private$student_age(),
        " in age years\n",
        sep = ""
      )
      cat("\tHair Color:", private$hair_color, "\n", sep = "")
    }
  ),
  private = list(
    name = NULL,
    age = NULL,
    hair_color = NULL,
    student_age = function() {
      return(private$age * 7)
    }
  )
)

s1 <- student$new(name = "acs", age = 14, hair_color = "xyx")
print(s1)
print(s1$say_hello)
print(s1$student_age)
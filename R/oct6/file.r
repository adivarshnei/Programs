# Creating a Class using R6 package
library(package = "R6")

# Poorly designed class
human <- R6Class(
  classname = "human",

  # Public Elements
  public = list(
    name = NULL,
    age = NULL,
    id = NULL
  )
)

# Creating empty object
h1 <- human$new

# h1 <- human$new(name = "Test", age = 25, id = "12345")     Commented out as
#                                                            there is no init
#                                                            method

# Class with initialize method
human2 <- R6Class(
  classname = "human",
  public = list(
    name = NULL,
    age = NULL,
    id = NULL,

    # Essentially a constructor function
    initialize = function(name = NA, age = NA, id = NA) {
      self$name <- name
      self$age <- age
      self$id <- id
      private$test <- 123
    }
  ),

  # Private Elements
  private = list(
    test = NULL
  )
)

# Defining class method outside class
human2$set("public", "print_vals", function() {
  cat(
    "Name:", self$name,
    "\nAge:", self$age,
    "\nID:", self$id,
    "\nTest:", private$test, "\n"
  )
})

# Creating Object
h2 <- human2$new(name = "Test", age = 25, id = "12345")
print(h2)

h2$print_vals()

print(h2$name)

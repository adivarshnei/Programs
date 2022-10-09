library(package = "R6")

human <- R6Class(
  classname = "Human",
  public = list(
    initialize = function(name = NA, age = NA, no_of_eyes = NA) {
      private$name <- name
      private$age <- age
      private$no_of_eyes <- no_of_eyes
    },
    make_sound = function(sound) {
      cat(private$name, " says ", sound, "\n", sep = "")
    }
  ),
  private = list(
    name = NULL,
    age = NULL,
    no_of_eyes = NULL
  )
)

student <- R6Class(
  classname = "student",
  inherit = human,
  public = list(
    initialize = function(name = NA,
                          age = NA,
                          no_of_eyes = NA,
                          hair_color = NA) {
      super$initialize(name, age, no_of_eyes)
      private$hair_color <- hair_color
    }
  ),
  private = list(
    hair_color = NULL
  )
)

s1 <- student$new(name = "ABC", age = 14, no_of_eyes = 4, hair_color = "abc")
print(s1)
s1$make_sound(sound = "hello")
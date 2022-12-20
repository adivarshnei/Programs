func <- function() {
}

class(func)

print_name <- function(name) {
	cat("Name: ", name, "\n")
}

name <- scan("stdin", what = integer(0), n = 5)

print_name(name)

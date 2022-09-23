func <- function() {
}

class(func)

print_name <- function(name) {
	cat("Name: ", name, "\n")
}

name <- scan(stdin)

print_name(name)
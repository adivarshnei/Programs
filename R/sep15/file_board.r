# DataFrames
# A DataFrame is a 2D arraylike structure

# Creating a Dataframe
team_names <- c(
  "England",
  "Australia",
  "India",
  "South Africa",
  "Pakistan",
  "New Zealand",
  "West Indies",
  "Sri Lanka"
)

curr_capt <- c(
  "Stokes",
  "Cummins",
  "Sharma",
  "Elgar",
  "Azam",
  "Williamson",
  "Braithwaite",
  "Karunaratne"
)

wins <- c(384, 400, 168, 175, 146, 109, 181, 98)

losses <- c(317, 227, 174, 156, 136, 181, 204, 117)

win_loss <- wins / losses

teams_data <- data.frame(
  "Current Captain" = curr_capt,
  "Wins" = wins,
  "Losses" = losses,
  "Win-Loss Record" = win_loss,
  row.names = team_names,
  stringsAsFactors = FALSE
)

print(teams_data)

# Printing Dataframe Structure
str(teams_data)

# Printing Dataframe Summary
summary(teams_data)

# Extracting Rows and Columns of a Dataframe
print(teams_data[2, ])
print(teams_data[, 2])

print(teams_data$Current.Captain)
print(teams_data[, "Current.Captain"])
print(teams_data["Australia", ])

# Adding Column to a Dataframe
teams_data$`Draws` <- c(354, 215, 220, 124, 164, 168, 169, 92)
# or
# cbind(teams_data, "Draws" = c(354, 215, 220, 124, 164, 168, 169, 92))
print(teams_data)

# Merging Columns of a Dataframe
cbind(
  teams_data,
  data.frame("Draws" = c(354, 215, 220, 124, 164, 168, 169, 92))
)

# Adding Row to a Dataframe
rbind(teams_data, "Bangladesh" = c("Haque", 16, 100, 16 / 100, 18))

# Merging Rows of a Dataframe
teams_data <- rbind(
  teams_data,
  data.frame(
    "Current.Captain" = c("Haque"),
    "Wins" = c(16),
    "Losses" = c(100),
    "Win.Loss.Record" = c(16 / 100),
    "Draws" = c(18),
    row.names = c("Bangladesh"),
    stringsAsFactors = FALSE
  )
)

print(teams_data)

# Dropping Row of a Dataframe
print(teams_data[-1, ]) # Drops first row

# Dropping Column of a Dataframe
print(teams_data[, -1]) # Drops first col

# DataFrames
# A DataFrame is a 2D arraylike structure

# DataFrame Creation
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

# Dataframe structure and summary
str(teams_data)
summary(teams_data)

# Accessing rows and columns
team_captains_data <- teams_data$`Current.Captain`

# Adding Column
teams_data$`Draws` <- c(354, 215, 220, 124, 164, 168, 169, 92)
# or
cbind(teams_data, "Draws" = c(354, 215, 220, 124, 164, 168, 169, 92))

# Merging Column
cbind(
  teams_data,
  data.frame("Draws" = c(354, 215, 220, 124, 164, 168, 169, 92))
)

# Adding Row
rbind(teams_data, "Bangladesh" = c("Haque", 16, 100, 16 / 100, 18))

# Merging Row
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

# Dropping Row
teams_data[-1, ] # Drops first row

# Dropping Column
teams_data[, -1] # Drops first col

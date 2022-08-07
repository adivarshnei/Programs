# Write a python program to add some days to your present date and print the
# date added.

from datetime import date, timedelta


def date_add(current_date, input_days):
    current_date_fmt = current_date.strftime("%B %d, %Y")

    print(f"Current date is: {current_date_fmt}")

    new_date = current_date + timedelta(days=input_days)
    new_date_fmt = new_date.strftime("%B %d, %Y")

    print(
        f"{input_days} after {current_date_fmt}, the date will be {new_date_fmt}"
    )


def main():
    current_date = date.today()
    input_days = int(input("Enter number of days to be added: "))

    date_add(current_date, input_days)


if __name__ == "__main__":
    main()

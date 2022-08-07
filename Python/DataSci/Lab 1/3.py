# Write a python program to print date, time using date and time functions

from datetime import datetime


def print_entered_date_time(entered_date_time):
    entered_date_time_fmt = entered_date_time.strftime("%B %d, %Y, %H:%M:%S")
    print(f"Entered date and time is: {entered_date_time_fmt}")


def main():
    input_day, input_month, input_year = map(
        int, input("Enter a date (DD MM YYYY): ").split()
    )
    input_hour, input_minute, input_second = map(
        int, input("Enter current time (HH MM SS): ").split()
    )

    entered_date_time = datetime(
        year=input_year,
        month=input_month,
        day=input_day,
        hour=input_hour,
        minute=input_minute,
        second=input_second,
    )

    print_entered_date_time(entered_date_time)


if __name__ == "__main__":
    main()

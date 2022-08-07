# Write a python program to print date, time for today and now.

from datetime import datetime


def print_date_time(date_time_now):
    date_time_now_fmt = date_time_now.strftime("%B %d, %Y, %H:%M:%S")
    print(f"Current Date and Time is: {date_time_now_fmt}")


def main():
    date_time_now = datetime.now()
    print_date_time(date_time_now)


if __name__ == "__main__":
    main()

# Program to print weekday from week number

def returnWeekday(weekNum):
    key = ['Sunday',
           'Monday',
           'Tuesday',
           'Wednesday',
           'Thursday',
           'Friday',
           'Saturday']
    
    return key[weekNum - 1]

weekNum = int(input("Enter the week number: "))

print(f"Day {weekNum} of the week is {returnWeekday(weekNum)}")
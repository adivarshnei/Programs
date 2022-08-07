# Program to convert seconds to hours minutes and seconds

def hoursMinSec(seconds):
    time = []
    time.append(seconds // 3600)
    time.append(seconds // 60 - time[0] * 60)
    time.append(seconds - time[0] * 3600 - time[1] * 60)
    
    return time

seconds = int(input("Enter the raw seconds: "))
print(f"{seconds} seconds = {hoursMinSec(seconds)[0]}:{hoursMinSec(seconds)[1]}:{hoursMinSec(seconds)[2]}")
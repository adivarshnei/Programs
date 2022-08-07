# Program to find years, weeks, days

def yearsWkDays(days):
    time = []
    time.append(days // 365)
    time.append((days - time[0] * 365) // 7)
    time.append(days - time[0] * 365 - time[1] * 7)
    
    return time

days = int(input("Enter the raw days: "))
print(f"{days} days = {yearsWkDays(days)[0]}:{yearsWkDays(days)[1]}:{yearsWkDays(days)[2]}")
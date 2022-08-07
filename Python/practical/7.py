# Program to check whether is leap year or not

def leapChk(yr):
    if yr % 4 == 0:
        if yr % 100 == 0:
            if yr % 400 == 0:
                return True
            else:
                return False
        else:
            return False
    else:
        return False

year = int(input(f"Enter the year: "))

if leapChk(year) == True:
    print(f"{year} is a leap year")
else:
    print(f"{year} is not a leap year")
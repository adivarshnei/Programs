// Program to find days between two dates

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

enum Bool {
    YES = 1,
    NO  = 0
};

typedef int  LoopVar;
typedef int  IntArr;
typedef char string;

struct Date {
    int  day;
    int  month;
    int  year;
    Bool isLeap;
};

Date dateEntry(void);
void printDate(Date);
Bool leapChk(int);
int  leapCounter(Date);
int  distanceBetweenDates(Date, Date);

int          shouldRepeat;
const IntArr daysPerMonth[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const string monthNames[12][15] = { "January", "February", "March",
                                    "April",   "May",      "June",
                                    "July",    "August",   "September",
                                    "October", "November", "December" };

int
main(void) {
    system("cls");

    Date date1, date2;
    int  distance;

    while ( 1 ) {
        std::cout << "Date 1" << std::endl;
        date1 = dateEntry();

        std::cout << "Date 2" << std::endl;
        date2 = dateEntry();

        std::cout << "Date 1: ";
        printDate(date1);
        std::cout << "Date 2: ";
        printDate(date2);

        distance = distanceBetweenDates(date1, date2);

        std::cout << "Distance between both dates is " << distance << " days"
                  << std::endl;

        std::cout << std::endl << "Repeat Program? (1 = YES): ";
        std::cin >> shouldRepeat;

        if ( shouldRepeat == 1 ) {
            continue;
        } else {
            break;
        }
    }

    system("pause");
    return 0;
}

Date
dateEntry(void) {
    Date inputDate;
    Bool isLeap;

    do {
        std::cout << "Enter the year: ";
        std::cin >> inputDate.year;

        if ( inputDate.year <= 0 ) {
            std::cout << "Invalid Year" << std::endl;
        } else {
            inputDate.isLeap = leapChk(inputDate.year);
        }
    } while ( inputDate.year <= 0 );

    do {
        std::cout << "Enter the month: ";
        std::cin >> inputDate.month;

        if ( inputDate.month <= 0 || inputDate.month > 12 ) {
            std::cout << "Invalid Month" << std::endl;
        }
    } while ( inputDate.month <= 0 || inputDate.month > 12 );

    do {
        std::cout << "Enter the day: ";
        std::cin >> inputDate.day;

        if ( inputDate.isLeap == YES && inputDate.month == 2 ) {
            if ( inputDate.day < 0 || inputDate.day > 29 ) {
                std::cout << "Invalid Day" << std::endl;
                continue;
            } else {
                break;
            }
        } else if ( inputDate.day < 0 ||
                    inputDate.day > daysPerMonth[inputDate.month - 1] ) {
            std::cout << "Invalid Day" << std::endl;
        }
    } while ( inputDate.day < 0 ||
              inputDate.day > daysPerMonth[inputDate.month - 1] );

    return inputDate;
}

inline void
printDate(Date date) {
    std::cout << date.day << " " << monthNames[date.month - 1] << ", "
              << date.year << std::endl;
}

Bool
leapChk(int year) {
    Bool isLeap;

    if ( year % 4 == 0 ) {
        isLeap = YES;

        if ( year % 100 == 0 ) {
            isLeap = NO;
        }
        if ( year % 400 == 0 ) {
            isLeap = YES;
        }
    }

    return isLeap;
}

int
leapCounter(Date date) {
    int leapCount = 0;

    if ( date.month < 2 ) {
        leapCount -= 1;
    }

    leapCount = date.year / 4 - date.year / 100 + date.year / 400;

    return leapCount;
}

int
distanceBetweenDates(Date date1, Date date2) {
    long int dist1 = 0;
    long int dist2 = 0;

    dist1 += date1.day;
    dist2 += date2.day;

    for ( LoopVar month = 1; month <= date1.month; month++ ) {
        dist1 += daysPerMonth[month - 1];
    }

    for ( LoopVar month = 1; month <= date2.month; month++ ) {
        dist2 += daysPerMonth[month - 1];
    }

    dist1 += date1.year * 365 + leapCounter(date1);
    dist2 += date2.year * 365 + leapCounter(date2);

    return abs(dist2 - dist1);
}

#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDayOfWeek(int year, int month, int day) {
    // Zeller's Congruence algorithm to calculate the day of the week
    if (month < 3) {
        month += 12;
        year--;
    }
    int h = (day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return h;
}

int getNumberOfDaysInMonth(int year, int month) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

void printCalendar(int year, int month) {
    printf("    %d - %d\n", month, year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int dayOfWeek = getDayOfWeek(year, month,0);
    int daysInMonth = getNumberOfDaysInMonth(year, month);

    for (int i = 0; i < dayOfWeek; i++) {
        printf("   ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((dayOfWeek + day) % 7 == 0 || day == daysInMonth) {
            printf("\n");
        }
    }
}

int main() {
    int year, month;

    printf("Enter year (e.g., 2023): ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month input.\n");
        return 1;
    }

    printCalendar(year, month);

    return 0;
}
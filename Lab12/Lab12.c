#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Написать программу-календарь. Пользователь может указать даты в формате:
	- гггг.мм.дд - программа вычисляет день недели соответствующий данной дате;
	- гггг.мм - программа выводит календарь за данный месяц;
	- гггг - календарь за год;
	- now - текущую дату.
	С учетом что не использовать весокосные года
*/

int day_of_week(int year, int month, int day) {
  if (month <= 2) {
    month += 12;
    year--;
  }
  int exact;
  int y = year % 100;
  int c = year / 100;
  exact = (day + (int)(2.6 * month - 0.2) + y + (y / 4) + (c / 4) - 2*c);
  int result = ((exact % 7) + 7 + 2) % 7;
  return result;
}
int days_in_month(int month, int year) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    return 29;
  return days[month - 1];
}

char *month_names [] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

void printCalendar(int year)
{
  printf("     Calendar - %d\n\n", year);
  for (i = 0; i < 12; i++) {
    int start = day_of_week(year, i + 1, 1);
    int total = days_in_month(i + 1, year);
    printf("%s\n", month_names[i]);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");
    int k;
    for (k = 0; k < start; k++)
      printf("     ");
    for (j = 1; j <= total; j++) {
      printf("%3d", j);
      if (++k > 6) {
        k = 0;
        printf("\n");
      }
    }
    if (k)
      printf("\n");
  }
  return;
}

void printMonth (int year, int month) {
  printf("     Month - %d\n\n", month);
    int start = day_of_week(year, month, 1);
    int total = days_in_month(month, year);
    printf("%s\n", month_names[month - 1 ]);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");
    int k;
    for (k = 0; k < start; k++)
      printf("     ");
    for (int j = 1; j <= total; j++) {
      printf("%5d", j);
      if (++k > 6) {
        k = 0;
        printf("\n");
      }
    }
  }

int main() {
  time_t currentTime;
  time(&currentTime);

  char data[100];
  int count = 0;
  int year, month, day;

  printf("Data: ");
  scanf("%99s", data);

  int len = strlen(data);

  for (int i = 0; i < len; i++) {
    if (data[i] == '.') {
      count++;
    }
  }

  //printf("?????????? ?????: %d\n", count);
  if (strcmp(data, "now") == 0) {
    printf("Current time: %s", ctime(&currentTime));    }
  else if (count == 1) {
    sscanf (data, "%d.%d", &year, &month);
    if (month < 1 || month > 12) {
      printf("Invalid month");
    }
    else {
      printMonth (year, month);
    }
  }
  else if (count == 2) {
    sscanf(data, "%d.%d.%d", &year, &month, &day);
    if (day < 1 || day > 31 || month < 1 || month > 12) {
      printf("Invalid data");
    }
    else {
      int result = day_of_week(year, month, day);
      char *days[] = {"Monday", "Tuesday", "Wednesday",
      "Thursday", "Friday", "Saturday", "Sunday"};
      printf("Day of week: %s\n", days[result]);
    }
  }
  else if (count == 0) {
    sscanf (data, "%d", &year);
    printf("Year: %d", year);
    printCalendar (year);
  }
  return 0;
}

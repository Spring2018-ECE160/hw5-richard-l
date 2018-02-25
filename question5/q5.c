#include <stdio.h>

/*
 * Hi Professor Hong, I guess error correction means negative, or invalid days
 * I'm using 1582 as the minimum because that's whenthe Gregorian 
 * Calendar was officially adopted. (See: https://en.wikipedia.org/wiki/Gregorian_calendar#Preparation)
 */

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day; ; returns -1 if invalid */
int day_of_year(int year, int month, int day) {
	int i, leap;
	if(year <= 1582 || month <=0 || month > 12 || day <= 0 || day > 31) {

		return -1;
	}
	else {
		leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
		for (i = 1; i < month; i++) {
			day += daytab[leap][i];
		}
		return day;
	}
}

/* month_day: set month, day from day of year; sets -1 for month and day if invalid */
void month_day(int year, int yearday, int *pmonth, int *pday)
{	
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	if(year <= 1582 || yearday <= 0 || (yearday >= 366 && leap == 0) || yearday > 366) {
		*pmonth = -1;
		*pday = -1;
		return;
	}
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
	
}

int main()  {
	int month;
	int day;
	int years[] =  {-1999,2018,2017,9999,2011};
	int months[] = {2,    -5,  12,   7,  4};
	int days[] =   {12,   23,  32,   4,  9};
	int yearsSize = sizeof(years)/sizeof(years[0]);
	for(int i = 0; i < yearsSize; i++) {
		int day_of_year_int = day_of_year(years[i],months[i],days[i]);
		if (day_of_year_int == -1) {
			printf("Invalid Input into Day of Year function for %d/%d/%d\n", years[i], months[i], days[i]);
		}
		else {
			printf("Day of the Year for date %d/%d/%d: %d\n", years[i], months[i], days[i], day_of_year_int);
		}	
	}
	printf("\n");
	int monthdays[] =   {17, 367, -5, 100, 200};
	int monthdaysSize = sizeof(monthdays)/sizeof(monthdays[0]);
	for(int i = 0; i < monthdaysSize; i++) {
		month_day(years[i], monthdays[i], &month, &day);
		//I could have done the less than 0 check here, but I figured you wanted
		//us to practice working with pointers
		if(month == -1 || day == -1) {
			printf("Invalid Input into Month-Day function for year %d, day %d\n", years[i], monthdays[i]);
			month = 0;
			day = 0;
		}
		else {
			printf("In year %d, day %d is Month: %d, Day: %d\n", years[i], monthdays[i], month, day);
		}	
	}

	return 0;
}

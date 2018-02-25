## Question 5

(K&R Exercise 5-8) There is no error checking in <code>day_of_year</code> or <code>month_day</code>. Remedy this defect and verify that all of the cases are covered with examples.

Compile Steps:

	gcc q5.c -o out5

Output:

	Invalid Input into Day of Year function for -1999/2/12
	Invalid Input into Day of Year function for 2018/-5/23
	Invalid Input into Day of Year function for 2017/12/32
	Day of the Year for date 9999/7/4: 185
	Day of the Year for date 2011/4/9: 99

	Invalid Input into Month-Day function for year -1999, day 17
	Invalid Input into Month-Day function for year 2018, day 367
	Invalid Input into Month-Day function for year 2017, day -5
	In year 9999, day 100 is Month: 4, Day: 10
	In year 2011, day 200 is Month: 7, Day: 19

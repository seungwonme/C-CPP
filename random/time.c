#include <time.h>
#include <stdio.h>

// struct tm {
// 	int	tm_sec;		/* seconds after the minute [0-60] */
// 	int	tm_min;		/* minutes after the hour [0-59] */
// 	int	tm_hour;	/* hours since midnight [0-23] */
// 	int	tm_mday;	/* day of the month [1-31] */
// 	int	tm_mon;		/* months since January [0-11] */
// 	int	tm_year;	/* years since 1900 */
// 	int	tm_wday;	/* days since Sunday [0-6] */
// 	int	tm_yday;	/* days since January 1 [0-365] */
// 	int	tm_isdst;	/* Daylight Savings Time flag */
// 	long	tm_gmtoff;	/* offset from UTC in seconds */
// 	char	*tm_zone;	/* timezone abbreviation */
// };

int	main(void)
{
	time_t	timer = time(NULL); // return 값으로는 Unix 운영체제가 공식 출시한 1970년 1월 1일 0시 0분 0초를 기점으로 현재까지 흐른 시간을 초단위로 나타낸다.

	struct tm* t = localtime(&timer);
	printf("time: %ld\n", timer);
	printf("year: %d\n", t->tm_year + 1900);
	printf("month: %d\n", t->tm_mon + 1);
	printf("day: %d\n", t->tm_mday);
	printf("hour: %d\n", t->tm_hour);
	printf("minute: %d\n", t->tm_min);
	printf("second: %d\n", t->tm_sec);
	printf("weekday: %d\n", t->tm_wday);
	printf("yearday: %d\n", t->tm_yday);
	printf("isdst: %d\n", t->tm_isdst);
	printf("gmtoff: %ld\n", t->tm_gmtoff);
	printf("zone: %s\n", t->tm_zone);
	return (0);
}

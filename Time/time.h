#ifndef TIME_h
#define TIME_h
#include "../boolean.h"

//#define HOURS(t) (t).hours
//#define MINUTES(t) (t).minutes
//#define SECONDS(t) (t).seconds

typedef struct Time {
	int hours;
	int minutes;
	int seconds;
} time;

int absolute(int a);
void CreateTime(time* t, int h, int m, int s);
boolean isTimeValid(int h, int m, int s);
void readTime(time *t);
void displayTime(time* t);
int timeToSeconds(time t);
time secondsToTime(int s);
int timeDifference(int a, int b);

#endif
// Fig. 9.8: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

// Time abstract data type definition
class Time {
private:
	int hour;
	int minute;
	int second;

public:
	Time(int h = 0, int m = 0, int s = 0);
	~Time();

	Time &setTime(int h, int m, int s);
	Time &setHour(int h);
	Time &setMinute(int m);
	Time &setSecond(int s);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	Time &tick();

	void printUniversal() const;
	void printStandard() const;
};

#endif // !TIME_H

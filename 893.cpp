#include <iostream>

using namespace std;

bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
	int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	if(month == 2 && isLeap(year)) {
		return 29;
	} else {
		return d[month - 1];
	}
}

int main() {	
	
	int n, d, m, y;
	while(cin >> n >> d >> m >> y, !(n == 0 && d == 0 && m == 0 && y == 0)) {
	
		//Pass years
		while( n > 365 || ( !isLeap(y) && n >= 365 )) {
			int yearToCheck = y;

			if(m > 2) {
				yearToCheck++;
			}

			if(isLeap(yearToCheck)) {
				n -= 366;
			} else {
				n -= 365;
			}
			y++;
		}

		//Pass days
		while(n--) {
			
			if(d < daysInMonth(y, m)) {
				d++;
			} else {
				d = 1;
				if(m < 12) {
					m++;
				} else {
					m = 1;
					y++;
				}
			}

		}

		printf("%d %d %d\n", d, m, y);
	}


	return 0;
}

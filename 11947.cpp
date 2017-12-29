#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
typedef pair<string, iiii> zs_t;

bool isLeap(int y) {
	return ( y % 4 == 0 && y % 100 != 0 ) || (y % 400 == 0);
}

int strToInt(const string& s) {
	int n = 0;
	int result = 0;
	for(int i = s.size() - 1; i >= 0; i--) {
		result += pow(10, n) * (s[i] - '0');
		n++;
	}
	return result;
}

int daysInMonth(int year, int month) {
	int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
	if(month == 2 && isLeap(year)) {
		return 29;
	} else {
		return d[month - 1];
	}
}

bool between(int day, int month, int sM, int sD, int eM, int eD) {
	
	if(eM < sM) {
		return between(day, month, sM, sD, 12, 31) || between(day, month, 1, 1, eM, eD);
	}
	
	bool greaterThan = month > sM || ( month == sM && day >= sD );
	bool lesserThan = month < eM || ( month == eM && day <= eD );	
	
	return greaterThan && lesserThan;
}

int main() {	
	
	int N;
	cin >> N;
	int iteration = 1;

	while(N--) {
		string s;
		cin >> s;
		
		//Parse string
		string mS;
		mS.push_back(s[0]); mS.push_back(s[1]);
		string dS;
		dS.push_back(s[2]); dS.push_back(s[3]);
		string yS;
		yS.push_back(s[4]); yS.push_back(s[5]); yS.push_back(s[6]); yS.push_back(s[7]);

		int m = strToInt(mS), d = strToInt(dS), y = strToInt(yS);
		
		int n = 280;
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

		#define zsD(S, A, B, C, D) zs_t(S, make_pair(ii(A, B), ii(C, D)))
		
		//get zodiac sign
		//month/day - month/day
		vector<zs_t> v = {
			zsD("aquarius", 1, 21, 2, 19),
			zsD("pisces", 2, 20, 3, 20),
			zsD("aries", 3, 21, 4, 20),
			zsD("taurus", 4, 21, 5,21),
			zsD("gemini", 5, 22, 6, 21),
			zsD("cancer", 6, 22, 7, 22),
			zsD("leo", 7, 23, 8, 21),
			zsD("virgo", 8, 22, 9, 23),
			zsD("libra", 9, 24, 10, 23),
			zsD("scorpio", 10, 24, 11, 22),
			zsD("sagittarius", 11, 23, 12, 22),
			zsD("capricorn", 12, 23, 1, 20)
		};	

		printf("%d %.2d/%.2d/%d ", iteration, m, d, y);

		for(zs_t& e : v) {
			if(between(d, m, e.second.first.first, e.second.first.second, e.second.second.first, e.second.second.second)) {
				cout << e.first << endl;
				break;
			}
		}

		iteration++;
	}

	return 0;
}

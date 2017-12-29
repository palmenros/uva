#include <iostream>
#include <vector>

using namespace std;

bool isGreen(int signal, int second) {
	int time = second % (2 * signal);
	return time < (signal - 5);
}

int main() {	
	
	int n;
	while(cin >> n) {

		if(n == 0) {
			int a, b;
			cin >> a >> b;
			if(a == 0 && b == 0) {
				break;
			}
		}
	
		vector<int> v;

		do {
			v.push_back(n);
		} while(cin >> n, n != 0);
	
		int se = -1;
		for(int i = 0; i <= 18000; i++) {
			bool allGreen = true;
			for(int signal : v) {
				allGreen = allGreen & isGreen(signal, i);
			}
			if(!allGreen && se == -1) {
				se = 0;
			}
			if(allGreen && se == 0) {
				se = i;
				break;
			}
		}

		if(se > 0) {
			int hours = se / 3600;
			int minutes = (se / 60) % 60;
			int seconds = se % 60;
			printf("%.2d:%.2d:%.2d\n", hours, minutes, seconds);
		} else {
			printf("Signals fail to synchronise in 5 hours\n");
		}

	}
	return 0;
}

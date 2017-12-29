#include <iostream>
#include <string>
#include <string.h>
#include <bitset>

using namespace std;

int main() {	
	
	int n;
	while(cin >> n){
	
		int last;
		cin >> last;

		bitset<3000> b;

		for(int i = 1; i < n; i++) {
			int v;
			cin >> v;
		
			int diff = abs(last - v);
			last = v;
			b.set(diff, true);
		}	

		bool jolly = true;
	
		for(int i = 1; i < n; i++) {
			jolly &= b.test(i);
		}

		if(jolly) {
			printf("Jolly\n");
		} else {
			printf("Not jolly\n");
		}

	}

	return 0;
}

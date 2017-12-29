#include <iostream>
#include <cmath>

using namespace std;

int main() {	
	int N;
	cin >> N;

	while(N--) {
		int n, k;
		cin >> n >> k;
			
		int result = 0;
		for(int i = 0; i < n; i++) {
			int val = k % (4 * int(pow(2, i)));	
			if( val >= pow(2, i) && val < 3 * pow(2, i) ) {
				//Set bit to 1
				result |= (1 << i);
			}	
		}
	
		cout << result << endl;

	}

	return 0;
}

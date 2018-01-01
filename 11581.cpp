#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <memory.h>

using namespace std;

int get(bool g[3][3], int x, int y) {
	if(x >= 0 && x < 3 && y >= 0 && y < 3) {
		return g[x][y];
	}
	return 0;
}

void f(bool g[3][3], bool output[3][3]) {
	for(int y = 0; y < 3; y++) {
		for(int x = 0; x < 3; x++) {
			int sum = 0;
			sum += get(g, x + 1, y);
			sum += get(g, x - 1, y);
			sum += get(g, x, y + 1);
			sum += get(g, x, y - 1);
			
			sum = sum % 2;
			output[x][y] = sum;	
		}
	}	
}

bool allZero(bool g[3][3]) {
	for(int y = 0; y < 3; y++) {
		for(int x = 0; x < 3; x++) {
			if(g[x][y] == 1) {
				return false;
			}
		}
	}
	return true;
}

int main() {	
	int N;
	cin >> N;
	cin.ignore();

	while(N--) {
		cin.ignore();

		//g[x][y]
		bool g[3][3];
		for(int i = 0; i < 3; i++) {
			string str;
			getline(cin, str);
			g[0][i] = str[0] == '1';
			g[1][i] = str[1] == '1';
			g[2][i] = str[2] == '1';
		}
		
		bool o[3][3];

		int n = 0;
		while(!allZero(g)) {
			f(g, o);
			memcpy(g, o, sizeof(bool) * 3 * 3);
			n++;
		}

		printf("%d\n", n - 1);
	}

	return 0;
}

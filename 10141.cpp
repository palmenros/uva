#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main() {	
	int N = 1;
	int n, p;
	while(cin >> n >> p, !(n == 0 && p == 0)) {
		
		cin.ignore();
		for(int i = 0; i < n; i++) {
			string tmp;
			getline(cin, tmp);
		}

		float bc = 0;
		int bcPrice = INT_MAX;
		string bcName;

		for(int i = 0; i < p; i++) {
			string name;
			getline(cin, name);
			float price;
			int rm;
			
			cin >> price >> rm;
			cin.ignore();
	
			for(int j = 0; j < rm; j++) {
				string trash;
				getline(cin, trash);
			}

			float compliance = float(rm) / n;
			if(compliance >= bc) {
				if(compliance > bc || price < bcPrice) {
					bc = compliance;
					bcPrice = price;
					bcName = name;
				}
			}
		}
	
		if(N != 1) {
			printf("\n");
		}

		printf("RFP #%d\n%s\n", N, bcName.c_str());
		N++;
	}

	return 0;
}

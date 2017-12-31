#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {	
	int S, B;
	
	int R[100100];
	int L[100100];

	while(cin >> S >> B, !(S == 0 && B == 0)) {
		
		for(int i = 0; i <= S; i++) {
			L[i] = i - 1;
			R[i] = i + 1;
		}
	
		for(int i = 0; i < B; i++) {
			int s, e;
			cin >> s >> e;
		
			if(L[s] >= 1) {
				printf("%d ", L[s]);
			} else {
				printf("* ");
			}

			if(R[e] <= S) {
				printf("%d\n", R[e]);
			} else {
				printf("*\n");
			}

			L[R[e]] = L[s];
			R[L[s]] = R[e];
		}

		cout << "-" << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

char get(const string& str, int x, int y) {
	int side = sqrt(str.size());
	return str[ x + y * side ];
}

int main() {	
	int N;
	cin >> N;
	cin.ignore();
	for(int caseNumber = 0; caseNumber < N; caseNumber++) {
	
		string unfiltered;
		getline(cin, unfiltered);

		string filtered;
		for(char c : unfiltered) {
			if(c >= 'a' && c <= 'z') {
				filtered.push_back(c);
			}
		}
	
		float dimf = sqrt(filtered.size());
		int dim = (int) dimf;
	
		printf("Case #%d:\n", caseNumber + 1);

		if(dimf != dim) {
			//Not a perfect square
			printf("No magic :(\n");
			continue;
		}
		
		bool magic = true;

		string& s = filtered;
		int i = 0;
		for(int x = 0; x < dim; x++) {
			for(int y = 0; y < dim; y++) {
				if(get(s, x, y) != s[i]) {
					magic = false;
					goto end;
				}
				i++;
			}
		}

		i = 0;
		for(int y = 0; y < dim; y++) {
			for(int x = 0; x < dim; x++) {
				if(get(s, x, y) != s[i]) {
					magic = false;
					goto end;
				}
				i++;
			}
		}

		i = 0;
		for(int x = dim - 1; x >= 0; x--) {
			for(int y = dim - 1; y >= 0; y--) {
				if(get(s, x, y) != s[i]) {
					magic = false;
					goto end;
				}
				i++;
			}
		}

		i = 0;
		for(int y = dim - 1; y >= 0; y--) {
			for(int x = dim - 1; x >= 0; x--) {
				if(get(s, x, y) != s[i]) {
					magic = false;
					goto end;
				}
				i++;
			}
		}

	end:
		if(magic) {
			printf("%d\n", dim);
		} else {
			printf("No magic :(\n");
		}

	}
	

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool capitalized(char c) {
	return c >= 'A' && c <= 'Z';
}

bool compare(char a, char b) {
	bool cA = capitalized(a);
	bool cB = capitalized(b);
	
	char minA = a, minB = b;
	if(cA) {
		minA = a - 'A' + 'a';
	}

	if(cB) {
		minB = b - 'A' + 'a';
	}

	if(cA == cB) {
		return a < b;
	} else {
		if(minA == minB) {
			return cA;
		} else {
			return minA < minB;
		}
	}

}

int main() {	
	int N;
	cin >> N;

	while(N--) {
		string tmp;
		cin >> tmp;

		sort(tmp.begin(), tmp.end(), compare);

		do {
			printf("%s\n", tmp.c_str());
		} while(next_permutation(tmp.begin(), tmp.end(), compare));

	}
	
	return 0;
}

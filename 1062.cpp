#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {	
	
	int N = 1;
	string str;
	while(getline(cin, str), str != "end") {

		vector<char> v;
		v.push_back(str[0]);

		for(unsigned int i = 1; i < str.length(); i++) {
			bool added = false;
			for(char& c : v) {
				if(str[i] <= c) {
					c = str[i];
					added = true;
					break;
				}
			}

			if(!added) {
				v.push_back(str[i]);
			}
		}

		printf("Case %d: %zu\n", N, v.size());

		N++;
	}

	return 0;
}

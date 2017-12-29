#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

	string input;
	while(cin >> input) {
		deque<char> str;
		
		string s;
		bool buffer = false;
		
		for(char c : input) {

			if(c == '[') {
				buffer = true;
				if(s.length() != 0) {
					str.insert(str.begin(), s.begin(), s.end());
					s = "";
				}
			} else if (c == ']') {
				buffer = false;
				if(s.length() != 0) {
					str.insert(str.begin(), s.begin(), s.end());
					s = "";
				}
			} else {

				if(buffer) {
					s.push_back(c);
				} else {
					str.push_back(c);
				}

			}
		}	
	
		if(s.length() != 0) {
			str.insert(str.begin(), s.begin(), s.end());
		}

		for(char c : str) {
			cout << c;
		}

		cout << endl;

	}
	
	return 0;
}

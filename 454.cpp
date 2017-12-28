#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool anagram(string a, string b) {
	a.erase(remove(a.begin(), a.end(), ' '), a.end());
	b.erase(remove(b.begin(), b.end(), ' '), b.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main() {	

	int N;
	cin >> N;
	cin.ignore();
	cin.ignore();

	while(N--) {
		
		set<string> s;
		
		string tmp;
		while(getline(cin, tmp), tmp != "") {
			s.emplace(tmp);
		}

		for(const string& s1 : s) {
			for(const string& s2 : s) {
				if(s1 < s2 && anagram(s1, s2)) {
					printf("%s = %s\n", s1.c_str(), s2.c_str());	
				}
			}
		}

		if(N != 0) {
			printf("\n");
		}
	}

	return 0;
}

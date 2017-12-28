#include <iostream>
#include <map>
#include <string>


using namespace std;

bool isPalindrome(const string& str) {
	for(int i = 0, j = str.size() - 1; i < j; i++, j--) {
		if(str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

bool isMirrored(const string& str) {
	map<char, char> m;
	//Populate map
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';
	
	string cpy = str;
	for(char& c : cpy) {
		if(m.find(c) == m.end()) {
			return false;
		}
		c = m[c];
	}
	
	for(int i = 0, j = str.size() - 1; i < j; i++, j--) {
		if(str[i] != cpy[j]) {
			return false;
		}			
	}

	return true;
}

int main() {	
	
	string str;
	while(cin >> str) {
		bool mirror = isMirrored(str), palin = isPalindrome(str);
		printf("%s -- ", str.c_str());
		if(mirror) {
			if(palin) {
				printf("is a mirrored palindrome");
			} else {
				printf("is a mirrored string");
			}
		} else {
			if(palin) {
				printf("is a regular palindrome");
			} else {
				printf("is not a palindrome");
			}
		}
		printf(".\n\n");
	}

	return 0;
}

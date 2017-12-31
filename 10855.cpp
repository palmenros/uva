#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef const vector<string>& vs;

int get0(vs s, int a, int b) {
	return s[a][b];
}

int get90(vs s, int a, int b) {
	return s[s.size() - b - 1][a];
}

int get180(vs s, int a, int b) {
	return s[s.size() - a - 1][s.size() - b - 1];
}

int get270(vs s, int a, int b) {
	return s[b][s.size() - a - 1];
}

int ocurrences(const vector<string>& S, const vector<string>& s, int (*f)(vs, int, int)) {
	int o = 0;
	int N = S.size();
	int n = s.size();

	for(int i = 0; i <= N - n; i++) {
		for(int j = 0; j <=  N - n; j++) {

			bool equals = true;
			//Compare each letter of little square
			for(int a = 0; a < n; a++) {
				for(int b = 0; b < n; b++) {
					if(f(s, a, b) != S[i + a][j + b]) {
						equals = false;
						goto end;
					}	
				}
			}
end:
			o += equals;
		}
	}

	return o;
}


int main() {	
	
	int N, n;
	while(cin >> N >> n, !(N == 0 && n == 0)) {
		
		vector<string> S;
		vector<string> s;
	
		cin.ignore();

		string tmp;
		for(int i = 0; i < N; i++) {
			getline(cin, tmp);
			S.push_back(tmp);
		}
		
		for(int i = 0; i < n; i++) {
			getline(cin, tmp);
			s.push_back(tmp);
		}

		printf("%d ", ocurrences(S, s, &get0));
		printf("%d ", ocurrences(S, s, &get90));
		printf("%d ", ocurrences(S, s, &get180));
		printf("%d\n", ocurrences(S, s, &get270));
	}

	return 0;
}

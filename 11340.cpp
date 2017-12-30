#include <iostream>
#include <map>

using namespace std;

int main() {

	int N;
	cin >> N;

	while(N--) {

		int K;
		cin >> K;
		cin.ignore();

		map<char, int> m;

		while(K--) {
			char c;
			int v;
			cin >> c >> v;
			cin.ignore();
			m[c] = v;
		}

		int M;
		cin >> M;
		cin.ignore();

		double val = 0;
		while(M--) {
			string str;
			getline(cin, str);
			for(char& c : str) {
				auto it = m.find(c);
				if(it != m.end()) {
					val += it->second;
				}
			}
		}

		val /= 100.0;
	
		printf("%.2lf$\n", val);

	}
	
	return 0;
}

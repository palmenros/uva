#include <iostream>
#include <vector> 
using namespace std;

int main() {	
	
	int n;
	while(cin >> n, n) {
		vector<int> v;
		v.push_back(0);
		int i = 0;
		while(n != 0) {
			if(n & 1) {
				v.push_back(i);
			}
			i++;
			n >>= 1;
		}

		int a = 0;
		for(int i = 1; i < v.size(); i += 2) {
			a |= (1 << v[i]);
		}	

		int b = 0;
		for(int i = 2; i < v.size(); i += 2) {
			b |= (1 << v[i]);
		}

		cout << a << " " << b << endl;
	}

	return 0;
}

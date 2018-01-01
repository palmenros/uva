#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {	
	
	multiset<unsigned long long int> s;
	unsigned long long n, size = 0;
	while(cin >> n) {
		s.insert(n);
		size++;

		auto i = s.begin();
		if(size % 2 == 0) {
			int pos = size / 2 - 1;
			advance(i, pos);
			int a = *i;
			i++;
			int b = *i;
			unsigned long long median = (a + b) / 2.f;
			printf("%llu\n", median);
		} else {
			int pos = floor(size / 2.f);
			advance(i, pos);
			printf("%llu\n", *i);
		}

	}

	return 0;
}

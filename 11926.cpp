#include <iostream>
#include <bitset>
#include <cmath>
#include <memory.h>

using namespace std;

int main() {	
	int n, m;

	bool b[1000010];

	while(cin >> n >> m, !(n == 0 && m == 0)) {
		memset(b, 0, sizeof(bool) * 1000010);

		bool conflict = false;
		for(int i = 0; i < n; i++) {
			int s, e;
			cin >> s >> e;

			for(int j = s; j < e; j++) {
				if(b[j]) {
					conflict = true;
				}
				b[j] = true;
			}
			
		}

		for(int i = 0; i < m; i++) {
			int s, e, r;
			cin >> s >> e >> r;
			while(s < 1000000) {
		
				for(int j = s; j < e; j++) {
					if(b[j]) {
						conflict = true;
					}
					b[j] = true;
				}
			
				s += r;
				e = min(1000000, e + r);
			}
		}
	
		if(conflict) {
			printf("CONFLICT\n");
		} else {
			printf("NO CONFLICT\n");
		}
	}
	return 0;
}

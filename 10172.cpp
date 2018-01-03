#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {	
		
	int SET;
	cin >> SET;

	while(SET--) {
	
		int N, S, Q;
		cin >> N >> S >> Q;

		vector<queue<int> > v;

		for(int i = 0; i < N; i++) {
			int n, tmp;
			cin >> n;
			queue<int> q;
			for(int j = 0; j < n; j++) {
				cin >> tmp;
				q.push(tmp);
			}
			v.push_back(q);
		}

		int t = 0;

		stack<int> carrier;
		bool done = true;
		int buff = 0;
		do {
			done = true;
			for(int i = 0; i < N; i++) {

				bool worked  = false;

				while(!carrier.empty()) {
					if((i + 1) == carrier.top()) {
						t++;
						carrier.pop();
						worked = true;
					} else {
						if(v[i].size() < Q) {
							v[i].push(carrier.top());
							carrier.pop();
							t++;
							worked = true;
						} else {
							break;
						}
					}
				}

				while(v[i].size() > 0 && carrier.size() < S) {
					carrier.push(v[i].front());
					v[i].pop();
					t++;
					worked = true;
				}

				if(worked) {
					t += 2;
					t += buff;
					buff = 0;
				} else {
					buff += 2;
				}

				done = done && v[i].size() == 0;
			}

			done = done && carrier.empty();

		} while(!done);

		t -= 2;
		cout << t << endl;

	}

	return 0;
}

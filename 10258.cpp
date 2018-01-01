#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class Team {
public:
	int n;
	int problemsSolved;
	int time;
	
	vector<pair<bool, int>> problems;
	vector<int> t;

	bool s = false;

	Team(int n, int ps, int time)
		: n(n), problemsSolved(ps), time(time)
	{
		problems.assign(10, make_pair(false, 0));
		t.assign(10, 0);
	}

};

bool compare(const Team& a, const Team& b) {
	
	if(a.problemsSolved != b.problemsSolved) {
		return a.problemsSolved > b.problemsSolved;
	}

	if(a.time != b.time) {
		return a.time < b.time;
	}
	
	return a.n < b.n;
}

int main() {	
	int N;
	cin >> N;
	
	cin.ignore();
	cin.ignore();

	while(N--) {

		int c, p, t;
		char L;
	
		vector<Team> sc;
		for(int i = 0; i < 105; i++) {
			sc.push_back(Team(i, 0,  0));
		}
	
		string line;
		while(getline(cin, line)) {

			if(line.empty()) {
				break;
			}

			sscanf(line.c_str(), "%d %d %d %c", &c, &p, &t, &L);
			sc[c].s = true;
			if(L == 'C' || L == 'I') {
				if(L == 'C') {
					if(!sc[c].problems[p].first) {
						sc[c].problems[p].first = true;
						sc[c].problems[p].second = t;
						sc[c].problemsSolved++;
					} else if(t < sc[c].problems[p].second) {
						sc[c].problems[p].second = t;
					}
				} else {
					if(!sc[c].problems[p].first) {
						sc[c].t[p] += 20;
					}
				}
			}
		}
	
		for(Team& t : sc) {
			for(int i = 0; i < 10; i++) {
				if(t.problems[i].first) {
					t.time += t.problems[i].second;
					t.time += t.t[i];
				}
			}
		}

		sort(sc.begin(), sc.end(), compare);
		for(Team& t : sc) {
			if(!t.s) {
				continue;
			}
			printf("%d %d %d\n", t.n, t.problemsSolved, t.time);
		}
		
		if(N != 0) {
			cout << endl;
		}
	}

	return 0;
}

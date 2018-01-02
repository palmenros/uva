#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	
	int N;
	while(cin >> N, N != 0) {
		
		int tmp;
		while(cin >> tmp) {
			if(tmp == 0) {
				break;
			}

			vector<int> v;
			v.push_back(tmp);

			for(int i = 1; i < N; i++) {
				cin >> tmp;		
				v.push_back(tmp);
			}

			bool possible = true;
			
			stack<int> s;

			int index = 0;
			for(int i : v){
				while(! (!s.empty() && s.top() == i) )  {
					if(index < N) {
						index++;
						s.push(index);
					} else {
						possible = false;
						goto end;
					}
				}
				s.pop();
			}

end:
			if(possible) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}

		}

		printf("\n");
	}
	return 0;
}

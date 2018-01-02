#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

void printOps(stack<int> s, string ops, string a, string b, string res, unsigned int aIndex, unsigned int bIndex)
{
	if(res.size() == b.size()) {
		if(res == b) {
			//Print operations
			cout << ops[0];
			for(unsigned int i = 1; i < ops.size(); i++) {
				cout << ' ' << ops[i];
			}
			cout << endl;
		}
		return;
	}

	if(aIndex < a.length()) {
		// i
		s.push(a[aIndex]);
		printOps(s, ops + 'i', a, b, res, aIndex + 1, bIndex);
		s.pop();
	}

	if(!s.empty() && s.top() == b[bIndex]) {
		//o
		res += s.top();
		s.pop();
		printOps(s, ops + 'o', a, b, res, aIndex, bIndex + 1);
	}

}

int main() {	
	
	string a, b;

	while(cin >> a >> b) {
		cout << "[" << endl;
		
		stack<int> s;
		printOps(s, "", a, b, "", 0, 0);

		cout << "]" << endl;
	}

	return 0;
}

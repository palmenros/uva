#include <iostream>
#include <vector>

using namespace std;

int main() {	
	int dim;
	int v[ 1 << 15 ];
	int p[ 1 << 15 ];
	while(cin >> dim) {
		for(int i = 0; i < (1 << dim); i++) {
			int tmp;
			cin >> tmp;
			v[i] = tmp;
		}

		//Calculate potencies
		for(int i = 0; i < (1 << dim); i++) {
			int sum = 0;
			for(int j = 0; j < dim; j++) {
				int neightbour = i ^ (1 << j);
				sum += v[neightbour];
			}
			p[i] = sum;
		}

		int max = 0;
		for(int i = 0; i < (1 << dim); i++) {
			for(int j = 0; j < dim; j++) {
				int neightbour = i ^ (1 << j);
				int sum = p[i] + p[neightbour];

				if(sum > max) {
					max = sum;
				}
			}
		}

		cout << max << endl;
	}

	return 0;
}

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Sheet {
public:
	pair<int, int> front;
	pair<int, int> back;

	Sheet(const pair<int, int>& front, const pair<int, int>& back) 
		: front(front), back(back) 
	{
	}
	
	Sheet()
	{
	};
};

void printFace(int number, int maxNumber) {
	if(number > maxNumber) {
		cout << "Blank";
	} else {
		cout << number;
	}
}

int main() {	
	int n;
	while(cin >> n, n != 0) {
		int sheetsNumber = ceil(n / 4.f);	
		vector<Sheet> v;
		for(int i = 0; i < sheetsNumber; i++) {
			v.push_back(Sheet(make_pair(0, 0), make_pair(0, 0)));
		}
		
		int sheet = 1;
		for(unsigned int i = 0; i < v.size(); i++) {
			v[i].front.second = sheet++;
			v[i].back.first = sheet++;
		}

		for(int i = v.size() - 1; i >= 0; i--) {
			v[i].back.second = sheet++;
			v[i].front.first = sheet++;
		}

		printf("Printing order for %d pages:\n", n);
		
		for(unsigned int i = 0; i < v.size(); i++) {
			printf("Sheet %d, front: ", i + 1);
			printFace(v[i].front.first, n);
			cout << ", ";
			printFace(v[i].front.second, n);
			cout << endl;
			
			if(! (v[i].back.first > n && v[i].back.second > n) ) {
				printf("Sheet %d, back : ", i + 1);
				printFace(v[i].back.first, n);
				cout << ", ";
				printFace(v[i].back.second, n);
				cout << endl;
			}
		
		}
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, float> ifl;

int main() {	
	
	int months;
	while(scanf("%d", &months), months > 0) {
		float downPayment, amount;
		int deprecationNumber;
		scanf("%f %f %d", &downPayment, &amount, &deprecationNumber);
		vector<ifl> deprecations;

		for(int i = 0; i < deprecationNumber; i++) {
			int month;
			float percentage;
			scanf("%d %f", &month, &percentage);
			deprecations.push_back(make_pair(month, percentage));
		}

		float owed = amount, value = amount + downPayment;
		float payment = owed / months;
		size_t i = 0;

		value -= value * deprecations[0].second;

		bool printed = false;	
		for(int month = 1; month <= months; month++) {
			if(owed < value) {
				printf("%d %s\n", month - 1, month  == 2 ? "month" : "months");
				printed = true;
				break;
			}
			
			owed -= payment;
			
			if(i < deprecations.size() && deprecations[i + 1].first == month) {
				i++;
			}

			float dep = deprecations[i].second;
			value -= dep * value;
		}

		if(!printed) {
			printf("%d months\n", months);
		}
	}

	return 0;
}

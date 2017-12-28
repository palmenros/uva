#include <iostream>
#include <deque>

using namespace std;

typedef pair<char, char> cc;

int value(const cc& card) {
	int val = 10;
	if(card.first >= '1' && card.first <= '9') {
		val = card.first - '0';
	} 
	return val;
}

int main() {	

	int N;
	scanf("%d", &N);

	for(int caseN = 0; caseN < N; caseN++) {
	
		deque<cc> fPile, sPile;

		for(int i = 0; i < 52; i++) {
			//get value
			char fc, sc;
			scanf(" %c%c", &fc, &sc);
				auto p = make_pair(fc, sc);
			if(i < 27) {
				fPile.push_front(p);
			} else {
				sPile.push_front(p);
			}
		}

		int Y = 0;
		for(int i = 0; i < 3; i++) {
			int X = value(fPile.front());
			Y += X;
			fPile.pop_front();
			for(int j = 0; j < (10 - X); j++) {
				fPile.pop_front();
			}
		}

		for(int i = 0; i < 25; i++) {
			auto card = sPile.back();
			sPile.pop_back();
			fPile.push_front(card);
		}

		auto c = *(fPile.end() - Y);

		printf("Case %d: %c%c\n", caseN + 1, c.first, c.second);
	}

	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> hand;

vector<char>& getSuit(char s) {
	switch(s) {
		case 'S':
			return hand[0];
		case 'H':
			return hand[1];
		case 'D':
			return hand[2];
		case 'C':
			return hand[3];
	}
}

void pushCard(char r, char suit) {
	auto& v = getSuit(suit);
	v.push_back(r);
}

bool isStopped(const vector<char>& suit) {
	bool a = find(suit.begin(), suit.end(), 'A') != suit.end();	
	bool b = find(suit.begin(), suit.end(), 'K') != suit.end() && suit.size() > 1;
	bool c = find(suit.begin(), suit.end(), 'Q') != suit.end() && suit.size() > 2;
	return a || b || c;
}

int getScoreNo567() {
	int score = 0;
	
	for(int i = 0; i < 4; i++) {
		auto& s = hand[i];
		for(char r : s) {
			if(r == 'A') {
				score += 4;
			} else if (r == 'K') {
				score += 3;
				if(s.size() == 1) {
					score--;
				}
			} else if (r == 'Q') {
				score += 2;
				if(s.size() < 3) {
					score--;
				}
			} else if (r == 'J') {
				score++;
				if(s.size() < 4) {
					score--;
				}
			}
		}
	}

	return score;
}

int getScore567() {
	int score = 0;
	for(int i = 0; i < 4; i++) {
		int size = hand[i].size();
		if(size == 2) {
			score++;
		} else if (size == 1) {
			score += 2;
		} else if (size == 0) {
			score += 2;
		}
	}
	return score;
}

int getScore() {
	return getScoreNo567() + getScore567();
}

int main() {	
	
	char firstRead;
	while(scanf(" %c", &firstRead) != EOF) {

		char secondRead;
		scanf("%c", &secondRead);
		
		hand.clear();
		hand.push_back(vector<char>());
		hand.push_back(vector<char>());
		hand.push_back(vector<char>());
		hand.push_back(vector<char>());

		pushCard(firstRead, secondRead);

		for(int i = 0; i < 12; i++) {
			char fc, sc;
			scanf(" %c%c", &fc, &sc);
			pushCard(fc, sc);
		}

		bool suitsStopped = true;
		for(int i = 0; i < 4; i++) {
			suitsStopped = suitsStopped && isStopped(hand[i]);
		}

		if(suitsStopped && getScoreNo567() >= 16) {
			printf("BID NO-TRUMP\n");
			continue;
		}
		
		if(getScore() < 14) {
			//Pass
			printf("PASS\n");
		} else {
			//Bid
			unsigned int longest = 0;
			char bid;
			char arr[] = {'S', 'H', 'D', 'C'};
			for(int i = 0; i < 4; i++) {
				if(hand[i].size() > longest) {
					longest = hand[i].size();
					bid = arr[i];
				}
			}
			printf("BID %c\n", bid);
		}

	}

	return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main() {	
	int S, P;
	while(cin >> S >> P, !(S == 0 && P == 0)) {
		P--;
		bool prev = false;
		int dir = 0;

		int movements = 1;
		int c = 0;

		//Coordinates from center
		int x = 0, y = 0;

		if(P > 8) {
			int s = floor(sqrt(P));
			if(s % 2 == 0) {
				s--;
			}

			c = s - 1;
			movements = s;
			
			P -= s * s - 1;
			// s: 1 3 5 7
			s--;
			// s: 0 2 4 6
			s /= 2;
			// s: 0 1 2 3
			x += s;
			y += s;

		
		}

		while(P-- > 0) {

			//Move
			switch(dir) {
				case 0:
					y++;
					break;
				case 1:
					x--;
					break;
				case 2:
					y--;
					break;
				case 3:
					x++;
					break;
			}
	
			c++;

			if(c == movements) {
				c = 0;
				dir = (dir + 1) % 4;

				if(prev) {
					movements++;
				}

				prev = !prev;
			}	
		}

		int center = ceil(S / 2.f);
		x += center;
		y += center;

		printf("Line = %d, column = %d.\n", y, x);

	}

	return 0;
}

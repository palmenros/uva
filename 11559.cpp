#include <iostream>
#include <limits.h>

using namespace std;

int main() {	
	
	int n, b, h, w;
	while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
		
		int minPrice = INT_MAX;

		for(int i = 0; i < h; i++) {
			int price;
			scanf("%d", &price);
	
			bool possible = false;

			for(int j = 0; j < w; j++) {
				int availableBeds;
				scanf("%d", &availableBeds);
				if(availableBeds >= n) {
					possible = true;
				}
			}
		
			int totalPrice = price * n;
			if(possible && totalPrice < minPrice) {
				minPrice = totalPrice;
			}
		}

		if(minPrice <= b) {
			printf("%d\n", minPrice);
		} else {
			printf("stay home\n");
		}
	}


	return 0;
}

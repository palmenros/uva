#include <iostream>
#include <cmath>

using namespace std;

int main() {	
	
	float h, m;
	while(scanf("%f:%f", &h, &m), !( h == 0 && m == 0 ))
	{
		float hs = 360.f / 12.f;
		float ms = 360.f / 60.f;

		float ma = ms * m;
		float ha = hs * h + ( hs * m / 60.f );
		
		float angle = ma - ha;
	
		if(angle < 0) {
			angle += 360;
		}

		if(angle > 180) {
			angle = 360 - angle;
		}

		printf("%.3f\n", angle);

	}
	return 0;
}

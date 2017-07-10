#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <complex>

using namespace std;


void solve(){
	float x, y;
	int r, N = 1;
	
	while(cin >> x >> y >> r){
		bool in = true;
		complex<float> prev(0.0,0.0);
		complex<float> zn;
		for (int i = 0; i < r; ++i)
		{
			zn = pow(prev,2) + complex<float>(x,y);
			//cout << zn << " " << abs(zn) << endl;
			if(abs(zn) > 2)
			{
				in = false;
				break;
			}

			prev = zn;
		}

		cout << "Case " << N++ << ": ";
		if(in)
			cout << "IN" << " " << endl;
		else
			cout << "OUT" << endl;

	}
	

}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
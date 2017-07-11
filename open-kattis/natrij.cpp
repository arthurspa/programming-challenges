#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>

using namespace std;

class Time{
public:
	int h;
	int m;
	int s;
};

Time t1, t2;

void solve(){
	string buf;
	int hSub, mSub, sSub;

	while(cin >> buf){		
		t1.h = stoi(buf.substr(0,2));
		t1.m = stoi(buf.substr(3,2));
		t1.s = stoi(buf.substr(6,2));

		cin >> buf;
		t2.h = stoi(buf.substr(0,2));
		t2.m = stoi(buf.substr(3,2));
		t2.s = stoi(buf.substr(6,2));

		sSub = mSub = hSub = 0;

		sSub = t2.s - t1.s;
		if(sSub < 0){
			sSub += 60;
			t1.m += 1;
		}


		if(t1.m >= 60){
			t1.m -= 60;
			t1.h += 1;
		}

		mSub = t2.m - t1.m;
		if(mSub < 0){
			mSub += 60;
			t1.h += 1;
		} else

		if(t1.h >= 24){
			t1.h -= 24;
		}
		hSub = t2.h - t1.h;
		if(hSub < 0){
			hSub += 24;
		}

		if(hSub == 0 && mSub == 0 && sSub == 0)
			hSub = 24;
		
		printf("%02d:%02d:%02d\n", hSub, mSub, sSub);
	}
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
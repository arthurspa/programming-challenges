#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <map>

using namespace std;


void solve(){
	int T, n, count = 0, taskTime, acumulated= 0;

	cin >> n >> T;

	for (int i = 0; i < n; ++i)
	{
		cin >> taskTime;

		if(acumulated + taskTime > T)
			break;

		acumulated += taskTime;

		count++;
	}

	cout << count;
	
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
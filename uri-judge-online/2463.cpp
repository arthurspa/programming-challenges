#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

using namespace std;

int N;
int rooms[50000];

int findMaxSum(){
	int absolut_max, local_max;
	absolut_max = rooms[0];
	local_max = rooms[0];

	for (int i = 1; i < N; ++i)
	{
		local_max =  (rooms[i] > local_max + rooms[i]) ? rooms[i] : local_max + rooms[i];
		//cout << local_max << " ";
		if(absolut_max < local_max)
			absolut_max = local_max;
	}

	return absolut_max;
}

void solve(){

	while(cin >> N){
		for (int i = 0; i < N; ++i)
		{
			cin >> rooms[i];
		}

		cout << findMaxSum() << endl;
	}

}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
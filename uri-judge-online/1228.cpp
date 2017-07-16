#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <algorithm>

using namespace std;


void solve(){
	int N;
	int s[24], e[24];
	int pos;
	int overtakes;

	while(cin >> N){
		for (int i = 0; i < N; ++i)	
			cin >> s[i];
		for (int i = 0; i < N; ++i) 
			cin >> e[i];

		overtakes = 0;
		for (int i = 0; i < N; ++i)
		{
			
			for (int j = 0; j < N; ++j)
			{
				if(s[i] == e[j]){
					pos = j;
					break;
				}
			}

			if(pos > i){
				for (int j = pos; j > i; --j)
				{
					swap(e[j], e[j-1]);
					overtakes++;
				}
			} else if(pos < i){
				for (int j = pos; j < i; ++j)
				{
					swap(e[j], e[j+1]);
					overtakes++;
				}
			}
		}

		cout << overtakes << endl;

	}
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
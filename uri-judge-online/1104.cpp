#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <algorithm>

using namespace std;


void solve(){
	int A[100001], B[100001], nA, nB, aux, onlyInA, onlyInB;

	while(cin >> nA && cin >> nB && nA != 0 && nB != 0){

		// initialize
		for (int i = 0; i < 100001; ++i)
		{
			A[i] = 0, B[i] = 0;
		}

		// read A
		for (int i = 0; i < nA; ++i)
		{
			cin >> aux;
			A[aux] = 1;
		}
		// read B
		for (int i = 0; i < nB; ++i)
		{
			cin >> aux;
			B[aux] = 1;
		}

		onlyInA = 0, onlyInB = 0;
		for (int i = 0; i < 100001; ++i)
		{
			if(A[i] == 1 && B[i] == 0){
				onlyInA++;
			}else if(B[i] == 1 && A[i] == 0)
				onlyInB++;
		}

		cout << min(onlyInA,onlyInB) << endl;
		
	}

}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
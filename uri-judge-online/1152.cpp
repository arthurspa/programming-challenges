#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

using namespace std;


void solve(){
	// My solution goes here

}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	// Workaround for issue 
	// https://github.com/Microsoft/vscode-cpptools/issues/466
	if(getenv("IS_DEBUG"))
		cout << endl;

	return 0;
}
#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <algorithm>

using namespace std;


char buff[10000];
int diff = abs('a' - 'A');

bool checkLetters(char a, char b){

	bool aIsLower = (a >= 'a' && a <= 'z');
	bool bIsLower = (b >= 'a' && b <= 'z');
	if(a == b)
	{
		return true;
	}else if (abs(a-b) == diff && 
				((aIsLower && !bIsLower) || (!aIsLower && bIsLower))
			){
		return true;
	}

	return false;
}




void solve(){

	cin >> 

	// cin.getline(buff, 10000, '\n');

	

	cout << checkLetters('A', 'A');

}

int main()
{
  if(getenv("IS_DEBUG"))
    FILE* f = freopen("input", "r", stdin);

  solve();    

  return 0;
}
#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <algorithm>

using namespace std;


int N;
char buff[1000];
char first, curr;

void solve(){

	cin >> N;
	getchar();
	for (int i = 0; i < N; ++i)
	{

		cin.getline(buff, 10000, '\n');

		int count = 0;
		bool firstIsSet = false;
		bool pendingPrint = false;

		while(buff[count] != '\0'){

			//cout << buff[count];
			curr = buff[count];
			if(firstIsSet && curr == ' ')
			{
				cout << first;
				firstIsSet = false;
				pendingPrint = false;
			}else if(!firstIsSet && curr != ' '){
				first = curr;
				firstIsSet = true;
				pendingPrint = true;
			}
			count++;
			
		}

		if(pendingPrint)
			cout << first;

		cout << endl;

	}

}

int main()
{
  if(getenv("IS_DEBUG"))
    FILE* f = freopen("input", "r", stdin);

  solve();    

  return 0;
}
#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <algorithm>

using namespace std;


int N;
char buff[10000];
void solve(){

	cin >> N;
	getchar();
	for (int i = 0; i < N; ++i)
	{

		cin.getline(buff, 10000, '\n');


		int len = 0;
		while(buff[len] != '\0')
			len++;

		reverse(&buff[0], &buff[len]);

		for (int j = 0; j < len; ++j)
		{

			bool valid = (buff[j] >= 'A' && buff[j] <= 'Z' || buff[j] >= 'a' && buff[j] <= 'z');
			
			if(j>= len/2){
				if(valid)
					buff[j]= buff[j] + 2;
				else
					buff[j] = buff[j] -1;
			}else
			{
				if(valid)
					buff[j]= buff[j] + 3;
			}
			
		}
		
		cout << buff << endl;
	}

	//cout << endl;
}

int main()
{
  if(getenv("IS_DEBUG"))
    FILE* f = freopen("input", "r", stdin);

  solve();    

  return 0;
}
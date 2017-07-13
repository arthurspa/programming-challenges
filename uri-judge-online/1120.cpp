#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <algorithm>

using namespace std;


char buff[10000];
char d;
char *n;
int first, size;
bool firstFound;

void solve(){

	cin.getline(buff, 10000, '\n');

	d = buff[0];
	n = &buff[2];

	while(d != '0' && n[0] != '0'){
		
		size = 0;
		while(n[size] != '\0'){
			if(n[size] == d)
				n[size] = '-';
			size++;
		}

		first = 0;
		while(n[first] == '0' || n[first] == '-'){
			first++;
		}

		int printed = 0;
		if(first < size){
			while(n[first] != '\0'){
				if(n[first] != '-'){
					cout << n[first];
					printed++;					
				}

				first++;
			}
		}

		if(printed == 0)
			cout << 0;

		cin.getline(buff, 10000, '\n');
		d = buff[0];
		n = &buff[2];

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
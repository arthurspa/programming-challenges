#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

using namespace std;


class Aluno{
public:
	bool isFlagUp;
	int number;
	int orientation; // 0 - north, 1 - east, 2 - south, 3 - west
};

int N, numFlagsUp;
Aluno arr[1000][1000];

void countFlags(int i, int j){	
	int nextPersonL, nextPersonC;

	arr[i][j].isFlagUp = true;
	numFlagsUp++;

	for (int turns = 0; turns < 4; ++turns)
	{
		arr[i][j].orientation = (arr[i][j].orientation + 1) % 4;

		switch(arr[i][j].orientation){
			case 0:
			nextPersonL = i-1;
			nextPersonC = j;
			break;
			case 1:
			nextPersonL = i;
			nextPersonC = j+1;
			break;
			case 2:
			nextPersonL = i+1;
			nextPersonC = j;
			break;
			case 3:
			nextPersonL = i;
			nextPersonC = j-1;
			break;
		}

		if(nextPersonL > 0 &&
			nextPersonC <= N &&
			!arr[nextPersonL][nextPersonC].isFlagUp &&
			arr[nextPersonL][nextPersonC].number >= arr[i][j].number){
			countFlags(nextPersonL, nextPersonC);
		}
	}
}

void solve(){

	while(cin >> N){
		int firstL, firstC;

		cin >> firstL >> firstC;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				Aluno aluno;
				cin >> aluno.number;	
				aluno.isFlagUp = false;
				aluno.orientation = 0;
				arr[i][j] = aluno;
			}
		}


		numFlagsUp = 0;

		countFlags(firstL, firstC);

		cout << numFlagsUp << endl;

	}

}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
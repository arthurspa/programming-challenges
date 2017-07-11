#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

using namespace std;

int N, M, C, num, hashed;
int **mat;
void solveTestCase(int iteration){
	
	

	cin >> M >> C;
	mat = new int*[M];
	for (int i = 0; i < M; ++i)
	{
		mat[i] = new int[200];

		for (int j = 0; j < 200; ++j)
		{
			mat[i][j] = 0;
		}
	}

	for (int i = 0; i < C; ++i)
	{
		cin >> num;
		hashed = num % M;
		for (int i = 0; i < C; ++i)
		{
			if(mat[hashed][i] == 0){
				mat[hashed][i] = num;
				break;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cout << i ;

		for (int j = 0; j < 200; ++j)
		{
			if(mat[i][j] == 0 || j == 199){
				printf(" -> \\");
				break;
			}else{
				printf(" -> %d", mat[i][j]);
			}
		}

		cout << endl;
	}

	for (int i = 0; i < M; ++i)
	{
		delete[] mat[i];
	}

	delete[] mat;

	
	if(iteration < N - 1)
		cout << endl;

}

void solve(){

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		solveTestCase(i);
	}
	
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
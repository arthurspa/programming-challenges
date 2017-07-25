#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

using namespace std;

#define MAX_SIZE 50

int mat[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE*MAX_SIZE];
int T, N, V, A, u, v, count, visitedCount;

void initialize(){
    for(int i = 0; i < MAX_SIZE; ++i)
        for(int j = 0; j < MAX_SIZE; ++j)
            mat[i][j] = 0;
    
    for(int i = 0; i < MAX_SIZE*MAX_SIZE; ++i)
        visited[i] = 0;
}

void dfs(int s){
    visited[s] = 1;    

    for(int i = 0; i < V; ++i){
        if(visited[i] == 0 && mat[s][i] == 1){
            count++;
            dfs(i);
            count++;
        }
    }
}

int printMat(){
    for(int i = 0; i < V; ++i){
        cout << i << " ";
        for(int j = 0; j < V; ++j){
            if(mat[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }      
            
}

int drawMaze(int s){
    count = 0;

    dfs(s);

    return count;
}

void solve(){	
    
    cin >> T;
    for(int x = 0; x < T; x++){
        // My solution goes here
        initialize();

        cin >> N >> V >> A;
        for(int i = 0; i < A; ++i){
            cin >> u >> v;
            mat[u][v] = 1;
            mat[v][u] = 1;
        }

        cout << drawMaze(N) << endl;
    }

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


// Input sample
// 2
// 0
// 16 15
// 0 4
// 2 3
// 6 2
// 8 9
// 10 9
// 8 12
// 14 15
// 14 10
// 6 5
// 10 11
// 11 7
// 4 8
// 0 1
// 1 2
// 12 13
// 1
// 9 6
// 1 2
// 1 4
// 4 7
// 7 8
// 4 1
// 4 3
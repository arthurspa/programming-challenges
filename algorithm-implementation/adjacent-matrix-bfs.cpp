#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <queue>

using namespace std;

#define SIZE 7

int mat[SIZE][SIZE];
int visited[SIZE];


bool isAvailable(int x, int y){
    return (mat[x][y] == 1) && (visited[y] == 0);
}

int getAvailableNeighbor(int x){
    for(int i = 0; i < SIZE; ++i){
        if(i != x && isAvailable(x,i))
        {
            return i;
        }
    }
    // No neighbor available
    return -1;
}

void bfs(int startNode){

    queue<int> mQueue;
    mQueue.push(startNode);
    visited[startNode] = 1;

    while(mQueue.size() > 0){

        // get available neighbors
        int available = getAvailableNeighbor(mQueue.front());
        while(available != -1){
            if(visited[available] == 0){
                mQueue.push(available);
                visited[available] = 1;
            }
            available = getAvailableNeighbor(mQueue.front());
        }

        cout << mQueue.front() << " ";
        mQueue.pop();
    }    
}

void initialize(){
    for(int i = 0; i < SIZE; ++i){
        visited[i] = 0;
    }

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            mat[i][j] = 0;
        }
    }
}

void solve(){
	// My solution goes here

    int a, b;
    int firstA, firstB;

    initialize();

    cin >> a >> b;

    firstA = a, firstB = b;
    while(!cin.eof()){
        mat[a][b] = 1;

        cin >> a >> b;
    }

    // starting from node 2, but it could be any existing node in the graph
    bfs(2);
    
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


// sample input
// 0 1
// 0 2
// 0 3
// 1 0
// 1 4
// 2 0
// 2 4
// 2 5
// 3 0
// 3 5
// 4 1
// 4 2
// 4 6
// 5 2
// 5 3
// 5 6
// 6 4
// 6 5

// sample output
// 2 0 4 5 1 3 6
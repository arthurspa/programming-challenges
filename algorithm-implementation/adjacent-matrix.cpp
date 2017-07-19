#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <vector>

using namespace std;

#define SIZE 7

int mat[SIZE][SIZE];
int visited[SIZE];
int allVisited[SIZE];

// 1 -> not visited
// 2 -> visited
// 3 -> all neighbors visited


void setVisited(int x, int y){
    mat[x][y] = 2;
    mat[y][x] = 2;
}

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

void traverse(int x){

    // set current as visited
    visited[x] = 1;

    // get available neighbor
    int available = getAvailableNeighbor(x);

    // No neighbor available
    if(available == -1){
        allVisited[x] = 1;
    // If available and not visited
    }else if (available >= 0){
        cout << x << " ";
        traverse(available);  
    }
}

void initialize(){
    for(int i = 0; i < SIZE; ++i){
        visited[i] = 0;
    }

    for(int i = 0; i < SIZE; ++i){
        allVisited[i] = 0;
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
    while(a != -1 && b != -1){
        mat[a][b] = 1;

        cin >> a >> b;
    }

    traverse(0);
    
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
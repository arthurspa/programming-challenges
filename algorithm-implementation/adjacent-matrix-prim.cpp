#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <vector>
#include <queue>

using namespace std;

#define SIZE 7
#define MAX_WEIGHT 10000

int mat[SIZE][SIZE];
int visited[SIZE];

// try to solve problem 
// https://www.urionlinejudge.com.br/judge/en/problems/view/1152

class LessComparator{
public:
    bool operator()(const int &lhs, const int &rhs){
        return lhs < rhs;
    }
};

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

int getCheaperNeighbor(){
    
    int minNeighbor = -1;;
    int minWeigth = MAX_WEIGHT;

    // Iterate over all visited
    for(int i = 0; i < SIZE; ++i){
        if(visited[i] == 1){
            // get neighbor with minimun cost and is not visited yet
            for(int j = 0; j < SIZE; ++j){
                if( j != i && visited[j] == 0 &&  (mat[i][j] > 0) && (mat[i][j] < minWeigth)){
                    minNeighbor = j;
                    minWeigth = mat[i][j];
                }
            }

        }
    }

    return minNeighbor;
}

void prim(int startNode){

    queue<int> mQueue;
    mQueue.push(startNode);
    visited[startNode] = 1;
    numVisited = 1;

    while(mQueue.size() > 0){

        // get cheaper neighbor
        int cheaperNeighbor = getCheaperNeighbor();
        while(cheaperNeighbor != -1){
            if(visited[cheaperNeighbor] == 0){
                mQueue.push(cheaperNeighbor);
                visited[cheaperNeighbor] = 1;
            }
            cheaperNeighbor = getCheaperNeighbor();
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

    int a, b, weigth;
    int firstA, firstB;

    initialize();

    cin >> a >> b >> weigth;

    firstA = a, firstB = b;
    while(!cin.eof()){
        mat[a][b] = weigth;

        cin >> a >> b >> weigth;
    }

    // starting from node 2, but it could be any existing node in the graph
    prim(2);
    
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
// 0 1 3
// 0 2 2
// 0 3 4
// 1 0 3
// 1 4 5
// 2 0 2
// 2 4 2
// 2 5 3
// 3 0 4
// 3 5 2
// 4 1 5
// 4 2 2
// 4 6 4
// 5 2 3
// 5 3 2
// 5 6 2
// 6 4 4
// 6 5 2

// sample output

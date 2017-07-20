#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <stack>
#include <queue>

using namespace std;

int n, c, x;

void solve(){
	//My solution goes here

    while(cin >> n){
        stack<int> s;
        priority_queue<int> pq;
        queue<int> q;
        bool isStack = true;
        bool isPriorityQueue = true;
        bool isQueue = true;

        for(int i = 0; i < n; ++i){
            cin >> c >> x;

            if(c == 1){
                s.push(x);
                pq.push(x);
                q.push(x);
            } else{
                try{
                    if(s.top() != x || s.size() == 0)
                    {
                        isStack = false;
                    }
                    s.pop();
                }catch(...){
                    isStack = false;
                }
                try{
                    if(pq.top() != x || pq.size() == 0)
                    {
                        isPriorityQueue = false;
                    }
                    pq.pop();
                }catch(...){
                    isPriorityQueue = false;
                }
                try{
                    if(q.front() != x || q.size() == 0)
                    {
                        isQueue = false;
                    }
                    q.pop();
                }catch(...){
                    isQueue = false;
                }
            }            
        }

        if(isStack && !isQueue && !isPriorityQueue){
            cout << "stack" << endl;
        } else if(isQueue && !isStack && !isPriorityQueue){
            cout << "queue" << endl;
        } else if(isPriorityQueue && !isStack && !isQueue){
            cout << "priority queue" << endl;
        } else if(isPriorityQueue && isStack ||
                    isPriorityQueue && isQueue ||  
                    isQueue && isStack){
            cout << "not sure" << endl;
        } else {
            cout << "impossible" << endl;
        }
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
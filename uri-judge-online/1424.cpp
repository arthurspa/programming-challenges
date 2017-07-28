#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <unordered_map>
#include <vector>

using namespace std;

int n, m, k, v;

void solve(){
	// My solution goes here
    int value, ans;    

    while(cin >> n >> m){
        unordered_map<int,vector<int>> found;

        for(int i = 1; i <= n; i++){
            cin >> value;
            found[value].push_back(i);
        }            
        
        for(int i = 0; i < m; i++){
            cin >> k >> v;
            ans = (found[v].size() == 0 || k > found[v].size()) ? 0 : found[v][k-1];
            cout << ans << endl;
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
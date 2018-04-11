#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <algorithm>

using namespace std;



void solve(){
    // My solution goes here

    int important[100];
    int N, K, ans = 0, importantCount = 0;

    cin >> N >> K;

    int l, t;
    for(int i = 0; i < N; i++){
        cin >> l >> t;
        if(t == 1){
            important[importantCount++] = l;
        }
        ans += l;
    }

    if(importantCount - K >0){
        int sortTop = importantCount-K;
        // sorts only top "sortTop" values that are less then the rest (important+sortTop)
        // Those values are the ones that will be subtracted from "ans" because they represent
        // contests that will be won
        partial_sort(important, important+sortTop, important+(importantCount));

        for (int i = 0; i < sortTop; i++)
        {
            // multiplied *2 because we have previously added
            // this value, so we should cancelate it and then subtract it, thus, 
            // removing two times
            ans -= 2*important[i];
        }
    }

    cout << ans << endl;
}

int main()
{

    if(getenv("IS_DEBUG")){
        string fullFileName(__FILE__);
        string fileNameWithoutExtension = fullFileName.substr(0,fullFileName.rfind('.'));
        string inputFileName = fileNameWithoutExtension.append(".input");
        freopen(inputFileName.c_str(), "r", stdin);
    }


    solve();

    // Workaround for issue 
    // https://github.com/Microsoft/vscode-cpptools/issues/466
    if(getenv("IS_DEBUG"))
        cout << endl;

    return 0;
}

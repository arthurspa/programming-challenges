#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    int arr1[51] = {0};
    int arr2[51] = {0};
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr1[i];
        arr2[arr1[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << arr2[arr2[i]] << endl;
    }
    return 0;
}

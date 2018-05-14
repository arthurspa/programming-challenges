#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x1, v1, x2, v2;
    string ans = "NO";
    
    cin >> x1 >> v1 >> x2 >> v2;
    
    if(v1 > v2 && ((x1-x2)%(v2-v1)) == 0)
    {
        ans = "YES";
    }
    
    cout << ans;
    
    return 0;
}

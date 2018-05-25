#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, b, sum = 0, temp;
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(i != k)
            sum += temp;
    }
    cin >> b;
    
    int billAnna = sum/2;
    if(billAnna == b)
        cout << "Bon Appetit" << endl;
    else
        cout << b - billAnna << endl;
    return 0;
}
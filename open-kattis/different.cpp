#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    freopen("input", "r", stdin);

    long long a, b;
    while(cin >> a >> b){
        cout << abs(a-b) << endl;
    }    

    return 0;
}
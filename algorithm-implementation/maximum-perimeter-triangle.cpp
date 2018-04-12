#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, (n)-1)
#define REP1(i, n) FOR(i, 1, (n))
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int)w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

void solve()
{
    vi sticks;
    int N, l;

    cin >> N;

    REP(i, N)
    {
        cin >> l;
        sticks.push_back(l);
    }

    sort(sticks.begin(), sticks.end());

    int index = -1;
    FORR(i, N - 1, 2)
    {
        if (sticks[i - 2] + sticks[i - 1] > sticks[i])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << -1;
    }
    else
    {
        cout << sticks[index - 2] << " " << sticks[index - 1] << " " << sticks[index];
    }
}

int main()
{

    if (getenv("IS_DEBUG"))
    {
        string fullFileName(__FILE__);
        string fileNameWithoutExtension = fullFileName.substr(0, fullFileName.rfind('.'));
        string inputFileName = fileNameWithoutExtension.append(".input");

        freopen(inputFileName.c_str(), "r", stdin);
    }

    solve();

    // Workaround for issue
    // https://github.com/Microsoft/vscode-cpptools/issues/466
    if (getenv("IS_DEBUG"))
        cout << endl;

    return 0;
}
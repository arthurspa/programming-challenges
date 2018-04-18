#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <ctime>

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

int g[10][10];
int n, m;
int ans;

bool checkPos(int i, int j)
{

    if (i < 0 || i > n ||
        j < 0 || j > m || // Out of boundary
        g[i][j] != 1      // Allready visited or its a "0"
    )
    {
        return false;
    }

    return true;
}

int dfs(int i, int j)
{
    int sum = 1;
    g[i][j] = 2; // mark visited

    FOR(r, -1, 1)
    {
        FOR(c, -1, 1)
        {
            if (!(r == 0 && c == 0) &&
                checkPos(i + r, j + c))
            {
                sum += dfs(i + r, j + c);
            }
        }
    }

    return sum;
}

void solve()
{
    // My solution goes here

    cin >> n >> m;

    REP(i, n)
    {
        REP(j, m)
        {
            cin >> g[i][j];
        }
    }

    ans = 0;
    REP(i, n)
    {
        REP(j, m)
        {
            if (checkPos(i, j))
            {
                int result = dfs(i, j);
                if (result > ans)
                {
                    ans = result;
                }
            }
        }
    }

    cout << ans;
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

    int start = clock();
    solve();
    int end = clock();

    // Workaround for issue
    // https://github.com/Microsoft/vscode-cpptools/issues/466
    if (getenv("IS_DEBUG"))
    {
        cout << endl
             << "[Finished in " << end - start << " ms]" << endl;
    }

    return 0;
}
#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define FORI(i, n) for (int(i) = 1; (i) <= (n); ++(i))
#define IN(x, y) ((y).find((x)) != (y).end())
#define ALL(t) t.begin(), t.end()
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++)
#define REP(i, a, b) for (int(i) = (a); (i) <= (b); ++i)
#define REPD(i, a, b) for (int(i) = (a); (i) >= (b); --i)
#define REMAX(a, b) (a) = max((a), (b));
#define REMIN(a, b) (a) = min((a), (b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari << " = " << (vari) << endl;

void solve()
{
    // My solution goes here
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
#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

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

    solve();

    // Workaround for issue
    // https://github.com/Microsoft/vscode-cpptools/issues/466
    if (getenv("IS_DEBUG"))
        cout << endl;

    return 0;
}
#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <set>

using namespace std;

void solve()
{
	// My solution goes here
	int w, p, arr[100], arrSize;
	set<int> nums;

	cin >> w >> p;
	arrSize = p + 2;

	arr[0] = 0;
	arr[arrSize - 1] = w;
	for (int i = 1; i < arrSize - 1; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = i+1; j < arrSize; j++)
		{
			nums.insert(arr[j]-arr[i]);
		}
	}

	set<int>::iterator it;
	for (it = nums.begin(); it != nums.end(); ++it)
	{
		cout << *it << " ";
	}
}

int main()
{
	if (getenv("IS_DEBUG"))
		FILE *f = freopen("input", "r", stdin);

	solve();

	// Workaround for issue
	// https://github.com/Microsoft/vscode-cpptools/issues/466
	if (getenv("IS_DEBUG"))
		cout << endl;

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int N;
int arr[1000];

void sort(int start, int end){
	int i = start;
	int j = end;
	int pivot = arr[(start+end)/2];
	int temp;

	while(i <= j){
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;

		if(i <= j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if( j > start)
		sort(start, j);

	if( i < end)
		sort(i, end);
}

void solve(){
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(0,N-1);

	
	if(N == 1){
		cout << arr[0];
	}else{
		int first = 0;
		int next;
		for (int i = 0; i < N - 1; ++i)
		{	
			next = i + 1;
			if(arr[next] - arr[i] > 1){
				if(i - first == 0){
					cout << arr[i] << " ";
				} else if(i - first == 1){
					cout << arr[first] << " " << arr[i] << " ";
				} else {
					cout << arr[first] << "-" << arr[i] << " ";
				}

				first = i+1;
			}
		}

		if(next - first == 0){
			cout << arr[next];
		} else if(next - first == 1){
			cout << arr[first] << " " << arr[next] << " ";
		} else {
			cout << arr[first] << "-" << arr[next] << " ";
		}
	}
	
}

int main()
{
    freopen("input", "r", stdin);

    solve();    

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N, K, C, S;


string solveTestCase(){

	stack<int> parkingLot;
	map<int,int> horarioentradaId;
	map<int,int> horarioSaidaId;
	int maxOut = 0;
	bool invalid = false;
	for (int id = 1; id <= N; ++id)
	{
		int in, out;
		cin >> in >> out;

		if(out > maxOut){
			maxOut = out;
		}
		//cout << "maxOut = " << maxOut << endl;

		if(in > out)
			invalid = true;

		horarioentradaId[in] = id;
		horarioSaidaId[out] = id;
	}

	if(invalid)
		return "Nao";

	for (int t = 1; t <= maxOut; ++t)
	{
		int idIn = horarioentradaId[t];
		int idOut = horarioSaidaId[t];

		// process out
		if(idOut > 0){
			if(parkingLot.size() == 0 || parkingLot.top() != idOut){
				return "Nao";
			}else
			{
				parkingLot.pop();
			}
		}		

		//process in
		if(idIn > 0){
			if( parkingLot.size() == K)
				return "Nao";

			parkingLot.push(idIn);
		}

	}

	if(parkingLot.size() > K)
		return "Nao";

	return "Sim";

}

void solve(){

	cin >> N >> K;
	while( N != 0 && K != 0){
		
		cout << solveTestCase() << endl;

		cin >> N >> K;
	}
	
}

int main(){
	//freopen("input","r", stdin);

	
	solve();

	return 0;
}
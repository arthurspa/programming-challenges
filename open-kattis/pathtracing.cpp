#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <string>
#include <map>

using namespace std;


class Point{
public:
	int x;
	int y;
};

void solve(){
	int minW, minH, maxW, maxH, wCount, hCount;
	Point points[501];
	int path[503][503];
	int totalPoints = 0;
	Point prevP;
	string move;

	minW = minH = maxW = maxH = wCount = hCount = 0;
	
	prevP.x = 0;
	prevP.y = 0;
	points[totalPoints++] = prevP;
	while(cin >> move){
		if(move.compare("left") == 0 || move.compare("right") == 0 )
		{
			if(move.compare("left") == 0){
				wCount--;
				prevP.x--;
			}
			else{
				wCount++;
				prevP.x++;
			}

			minW = min(minW, wCount);
			maxW = max(maxW, wCount);			
		}else{
			if(move.compare("down") == 0){
				hCount--;
				prevP.y--;
			}
			else{
				hCount++;
				prevP.y++;
			}
			minH = min(minH, hCount);	
			maxH = max(maxH, hCount);
		}

		points[totalPoints++] = prevP;
	}

	if(totalPoints > 1){		

		int dx = 0;
		int dy = 0;
		// Convert path to new coordinates
		for (int i = 0; i < totalPoints; ++i)
		{
			int val = 1; // indicates normal path
			if(i == 0)
				val = 2; // indicates the start
			else if(i == totalPoints - 1)
				val = 3; // indicates end of path
			
			dx = points[i].x - minW + 1;
			dy = maxH - points[i].y + 1;

			// Do not override start or end positions
			if(path[dx][dy] != 2 && path[dx][dy] != 3)
				path[dx][dy] = val;
		}

		int width = abs(minW) + maxW + 1 + 2;
		int height = abs(minH) + maxH + 1 + 2;
		// Print map
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				if(x == 0 || y == 0 || x == width - 1 || y == height - 1)
					cout << "#";
				else if(path[x][y] > 0){
					char val = '*';

					if(path[x][y] == 2)
						val = 'S';
					else if(path[x][y] == 3)
						val = 'E';
					cout << val;
				}else{
					cout << " ";
				}
			}

			cout << endl;
			
		}
	}
	
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
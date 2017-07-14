#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <queue>

using namespace std;

int C;
int N;
int endCount;

class node{
public:
	int value;
	node* right;
	node* left;
	bool created;

};

void addValue(node* rootNode, int value){


	if(!rootNode->created){
		rootNode->right = new node();
		rootNode->left = new node();
		rootNode->value = value;
		rootNode->created = true;
		// cout << "Created new " << value << endl;
	}else{
		if(value >= rootNode->value){				
			// cout << "Going right" << endl;
			addValue(rootNode->right, value);
			//cout << "Created right" << rootNode->right->value << endl;
		} else{
			// cout << "Going left" << endl;
			addValue(rootNode->left, value);
		}
	}

	return;
}

void printBFS(node* rootNode){
	queue<node*> mQueue;

	mQueue.push(rootNode);
	int count = 0;
	while(mQueue.size() > 0){
		if(mQueue.front()->left->created){
			mQueue.push(mQueue.front()->left);
		}
		if(mQueue.front()->right->created){
			mQueue.push(mQueue.front()->right);
		}

		cout << mQueue.front()->value;
		if(count++ < N -1)
			cout << " ";
		
		mQueue.pop();
	}

	cout << endl << endl;
}


void solve(){
	cin >> C;

	
	for (int i = 1; i <= C ; ++i)
	{
		cin >> N;

		node* rootNode = new node();

		for (int j = 0; j < N; ++j)
		{
			int v;
			cin >> v;
			addValue(rootNode, v);
		}

		cout << "Case " << i << ":" << endl;
		endCount = 0;
		printBFS(rootNode);

		// CLEAR ROOT

	}

	
}

int main()
{
  if(getenv("IS_DEBUG"))
    FILE* f = freopen("input", "r", stdin);

  solve();    

  return 0;
}
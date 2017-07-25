#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

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

void printPre(node* rootNode){
	cout << rootNode->value;
	if(endCount++ < N-1){		
		cout << " ";		
	}
	if(rootNode->left->created)
		printPre(rootNode->left);
	if(rootNode->right->created)
		printPre(rootNode->right);
}

void printIn(node* rootNode){	
	if(rootNode->left->created)
		printIn(rootNode->left);
	cout << rootNode->value;
	if(endCount++ < N-1){		
		cout << " ";		
	}
	if(rootNode->right->created)
		printIn(rootNode->right);
}

void printPost(node* rootNode){
	if(rootNode->left->created)
		printPost(rootNode->left);
	if(rootNode->right->created)
		printPost(rootNode->right);
	cout << rootNode->value;
	if(endCount++ < N-1){		
		cout << " ";		
	}
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
		cout << "Pre.: ";
		endCount = 0;
		printPre(rootNode);
		cout << endl;
		cout << "In..: ";
		endCount = 0;
		printIn(rootNode);
		cout << endl;
		cout << "Post: ";
		endCount = 0;
		printPost(rootNode);
		cout << endl << endl;

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
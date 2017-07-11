#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv

using namespace std;

typedef struct node{
	node* next;
	int value;
}node;

int N, M, C, num, hashed;
node **mat;
void solveTestCase(int iteration){	

	cin >> M >> C;
	mat = (node**)malloc(M*sizeof(node));
	for (int i = 0; i < M; ++i)
	{
		mat[i] = nullptr;
	}

	for (int i = 0; i < C; ++i)
	{
		cin >> num;
		hashed = num % M;
		node* newNode = (node*) malloc(sizeof(node));
		newNode->next = nullptr;
		newNode->value = num;
		if(mat[hashed] == nullptr){
			mat[hashed] = newNode;
		} else{
			node* it = mat[hashed];
			while(it->next != nullptr){
				it = it->next;
			}
			it->next = newNode;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		node* it = mat[i];
		printf("%d ->", i);

		if(it == nullptr){
			printf(" \\");
		}else{
			while(it->next != nullptr){
				printf(" %d ->", it->value);
				it = it->next;
			}

			printf(" %d -> \\", it->value);
		}

		cout << endl;
	}

	for (int i = 0; i < M; ++i)
	{
		node* it = mat[i];

		node* aux;
		while(it != nullptr){
			aux = it;
			it = it->next;
			delete aux;
		}
	}

	delete[] mat;

	
	if(iteration < N - 1)
		cout << endl;

}

void solve(){

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		solveTestCase(i);
	}
	
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	return 0;
}
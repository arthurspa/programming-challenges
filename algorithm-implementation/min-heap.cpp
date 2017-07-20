#include <iostream>
#include <stdio.h>	// stdin
#include <cstdlib> // getenv
#include <vector>

using namespace std;

class Heap{
    public:
    int *vector;
    int numElements;
    int size;

    Heap(int maxSize){
        this->vector = new int[maxSize + 1]();
        this->numElements = 0;
        this->size = maxSize;
    }

    ~Heap(){
        delete vector;
    }

    int getParentIndex(int current){
        return  current/2;
    }

    int getLeftChildIndex(int current){
        int index = 2*current;
        if(index > this->numElements){
            index =  -1;
        }

        return index;
    }

    int getRightChildIndex(int current){
        int index = 2*current + 1;
        if(index > this->numElements){
            index = -1;
        }

        return index;
    }

    int top(){
        if(this->numElements > 0){
            return this->vector[1];
        }
        else{
            throw;
        }
    }

    // Inserts element and returns the index
    int insert(int value){
        if(this->numElements == this->size){
            return -1;
        }
        // Adds element to the end of the heap
        this->vector[++this->numElements] = value;

        // while parent is higher than current value, pops
        // this value up in the tree
        int currentIndex = this->numElements;
        int parentIndex = this->getParentIndex(currentIndex);
        while(parentIndex > 0 &&
                this->vector[parentIndex] > this->vector[currentIndex])
        {
            
            swap(this->vector[parentIndex], this->vector[currentIndex]);

            currentIndex = parentIndex;
            parentIndex = this->getParentIndex(currentIndex);
        }

        return currentIndex;
    }

    void pop(){
        if(this->numElements != 0){           

            // Puts latest element on top of the heap
            int lastElementIndex = this->numElements;
            this->vector[1] = this->vector[lastElementIndex];
            this->numElements--;

            int currentIndex = 1;
            int leftChildIndex = this->getLeftChildIndex(currentIndex);
            int rightChildIndex = this->getRightChildIndex(currentIndex);
            while(leftChildIndex != -1 &&
                    rightChildIndex != -1){
                if(this->vector[currentIndex] > this->vector[leftChildIndex])
                {
                    swap(this->vector[currentIndex], this->vector[leftChildIndex]);
                    currentIndex = leftChildIndex;
                } else if(this->vector[currentIndex] > this->vector[rightChildIndex]){
                    swap(this->vector[currentIndex], this->vector[rightChildIndex]);
                    currentIndex = rightChildIndex;
                }

                leftChildIndex = this->getLeftChildIndex(currentIndex);
                rightChildIndex = this->getRightChildIndex(currentIndex);
            }
        }         
    }
};


void solve(){
    Heap heap = Heap(10);

    int x;
    while(cin >> x){
        heap.insert(x);
    }

    cout << "Min element is " << heap.top() << endl;

    cout << "Popping top element " << endl;
    heap.pop();

    cout << "Min element after pop is " << heap.top() << endl;
}

int main()
{
	if(getenv("IS_DEBUG"))
		FILE* f = freopen("input", "r", stdin);

	solve();    

	// Workaround for issue 
	// https://github.com/Microsoft/vscode-cpptools/issues/466
	if(getenv("IS_DEBUG"))
		cout << endl;

	return 0;
}
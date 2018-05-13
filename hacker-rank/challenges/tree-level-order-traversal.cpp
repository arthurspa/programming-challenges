// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <queue>

void levelOrder(node * root) {
    
    queue<node *> q;
    q.push(root);   
    
    node * curr;
    while(q.size() > 0){
        curr = q.front();
        cout << curr->data << " ";
    
        if(curr->left != nullptr)
            q.push(curr->left);
        if(curr->right != nullptr)
            q.push(curr->right);
        
        q.pop();
    }  
}
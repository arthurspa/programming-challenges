/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void printLeft(node *curr)
{
    if (curr == nullptr)
        return;

    printLeft(curr->left);

    cout << curr->data << " ";
}

void printRight(node *curr)
{
    if (curr == nullptr)
        return;

    cout << curr->data << " ";

    printRight(curr->right);
}

void topView(node *root)
{
    if (root == nullptr)
        return;

    if (root->left != nullptr)
    {
        printLeft(root->left);
        cout << root->data << " ";
    }
    else
    {
        cout << root->data << " ";
    }

    printRight(root->right);
}

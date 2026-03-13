#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node * left;
        Node * right;
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};
Node * make_array_to_binary_search_tree(int arr[], int l, int r)
{
    if(l > r) return NULL;
    int mid = (l+r)/2;
    Node * root = new Node(arr[mid]);
    Node * leftSubRoot = make_array_to_binary_search_tree(arr, l, mid-1);
    Node * rightSubRoot = make_array_to_binary_search_tree(arr, mid+1, r);
    root->left = leftSubRoot;
    root->right = rightSubRoot;
    return root;
};
void insert_in_bst(Node * &root, int val)
{
    Node * newNode = new Node(val);
    if(root==NULL){
        root = newNode;
        return;
    }
    if(root->val > val)
    {
        if(root->left)
        {
            insert_in_bst(root->left, val);
        }
        else
        {
            root->left = newNode;
        }
    }
    else
    {
        if(root->right)
        {
            insert_in_bst(root->right, val);
        }
        else
        {
            root->right = newNode;
        }
    }
}
bool isFound(Node * root, int x)
{
    if(root == NULL) return false;
    if(root->val == x) return true;
    if(root->val > x)
    {
        return isFound(root->left, x);
    }
    else return isFound(root->right, x);
}
void printLevelOrder(Node * root)
{
    if(root == NULL) return;
    queue<Node *> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node * f = q.front();
        q.pop();
        cout << f->val << endl;
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
};
int main() {
    int arr[] = {34, 35, 52, 24, 523, 525, 623, 325};
    sort(arr, arr+8); // nlogn complexity
    Node * root = make_array_to_binary_search_tree(arr, 0,7);
    insert_in_bst(root, 43);
    printLevelOrder(root);
    if(isFound(root, 24)) cout << "Found: 24";
    else cout << "NOT Found: 24"; 
    return 0;
}

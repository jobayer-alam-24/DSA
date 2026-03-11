#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node * left;
        Node * right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
Node * input_tree()
{
    int val;
    Node * root;
    cout << "Enter root value: ";
    cin >> val;
    // assume -1 means null
    if(val == -1) root = NULL;
    else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root); // root nije push korte hoy then other logic
    while(!q.empty())
    {
        // first logic: q theke ber kora
        Node * f = q.front();
        q.pop();
        // second: ja korbo seta.. task
        int l, r;
        Node * left, * right;
        cout << "Enter left value of " << f->val << " node : ";
        cin >> l;
        cout << "Enter right value of " << f->val << " node : ";
        cin >> r;
        if(l == -1) left = NULL;
        else left = new Node(l);
        if(r == -1) right = NULL;
        else right = new Node(r);
        if(left) f->left = left;
        if(right) f->right = right;
        // children guloke rakhbo
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    return root;
}
// Level Order Traversing
void level_order_print(Node * root)
{
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        // ber kora
        Node * f = q.front();
        q.pop();
        // oita niye kaj
        cout << f->val << endl;
        // children guloke rakha
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}
// Depth Order: pre-order, post-order, in-order
void pre_order(Node * root)
{
    if(root == NULL) return;
    cout << root->val << endl;
    pre_order(root->left);
    pre_order(root->right);
}
void post_order(Node * root)
{
    if(root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->val << endl;
}
void in_order(Node * root)
{
    if(root == NULL) return;
    in_order(root->left);
    cout << root->val << endl;
    in_order(root->right);
}
// Operations
int count_nodes(Node * root)
{
    if(root == NULL) return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l+r+1;
}
int count_leaf_nodes(Node * root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else
    {
        int l = count_leaf_nodes(root->left);
        int r = count_leaf_nodes(root->right);
        return l+r;
    } 
}
int max_height(Node * root)
{   
    if(root == NULL) return 0;
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l, r)+1;
}
int main() {
    Node * root = input_tree();
    cout << "PRE ORDER\n";
    pre_order(root);
    cout << "POST ORDER\n";
    post_order(root);
    cout << "IN ORDER\n";
    in_order(root);
    cout << "LEVEL ORDER\n";
    level_order_print(root);
    cout << "Total Nodes: " << count_nodes(root) << endl;
    cout << "Total Leaf Nodes: " << count_leaf_nodes(root) << endl;
    cout << "Maximum Height: " << max_height(root) << endl;
    return 0;
}
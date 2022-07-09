#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode *root, vector<int> &res)
{
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            res.push_back(root->val);
            root = root->left;
        }
        if (!s.empty())
        {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

void inorder(TreeNode *root, vector<int> &res)
{
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        if (!s.empty())
        {
            root = s.top();
            res.push_back(root->val);
            s.pop();
            root = root->right;
        }
    }
}

void postorder(TreeNode *root, vector<int> &res)
{
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        if (!s.empty())
        {
            root = s.top();
            s.pop();
            root = root->right;
            res.push_back(root->val);
        }
    }
}

void levelorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        res.push_back(root->val);
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}

/* 输出树中的叶子节点 */
void printLeaf(TreeNode *root)
{
    if (!root->left && !root->right)
    {
        cout << root->val;
    }
    printLeaf(root->left);
    printLeaf(root->right);
}

/* 求二叉树的高度 */
int treeHeight(TreeNode *root)
{
    int hl, hr, maxh;
    if (!root)
        return 0;
    hl = treeHeight(root->left);
    hr = treeHeight(root->right);
    maxh = hl > hr ? hl : hr;
    return maxh + 1;
}

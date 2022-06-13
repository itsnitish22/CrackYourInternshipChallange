#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left, *right;
    int val;
} * root;

void createTreeNode()
{
    root = new TreeNode;
    queue<TreeNode *> addr;

    int val;
    cout << "Enter root node\n";
    cin >> val;

    root->val = val;
    root->left = NULL;
    root->right = NULL;
    addr.push(root);

    TreeNode *temp;

    while (!addr.empty())
    {
        temp = addr.front();
        addr.pop();

        int l;
        cout << "Enter left node of " << temp->val << endl;
        cin >> l;

        if (l != -1)
        {
            TreeNode *q = new TreeNode;
            q->val = l;
            q->left = NULL;
            q->right = NULL;
            addr.push(q);
            temp->left = q;
        }
        cout << "Enter right node of " << temp->val << endl;
        cin >> l;

        if (l != -1)
        {
            TreeNode *q = new TreeNode;
            q->val = l;
            q->left = NULL;
            q->right = NULL;
            addr.push(q);
            temp->right = q;
        }
    }
}

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return root == NULL || Symmetric(root->left, root->right);
    }

    bool Symmetric(TreeNode *left, TreeNode *right)
    {
        if (!left || !right)
            return left == right;

        if (left->val != right->val)
            return false;

        return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    cout << s1.isSymmetric(root);
    return 0;
}
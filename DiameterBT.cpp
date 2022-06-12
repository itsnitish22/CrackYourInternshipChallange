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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        heightBT(root, maxi);
        return maxi;
    }

    int heightBT(TreeNode *root, int &maxi)
    {
        if (!root)
            return 0;

        int l = heightBT(root->left, maxi);
        int r = heightBT(root->right, maxi);

        maxi = max(maxi, l + r);

        return 1 + max(l, r);
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    cout << s1.diameterOfBinaryTree(root);
    return 0;
}
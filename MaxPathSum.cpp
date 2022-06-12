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
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        heightBT(root, maxi);
        return maxi;
    }

    int heightBT(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int l = max(0, heightBT(root->left, maxi));
        int r = max(0, heightBT(root->right, maxi));

        maxi = max(maxi, root->val + l + r);

        return root->val + max(l, r);
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    return 0;
}
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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = findHeightLeft(root->left);
        int rh = findHeightRight(root->right);

        if (lh == rh)
            return (2 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightLeft(TreeNode *node)
    {
        int hght = 0;
        while (node)
        {
            hght++;
            node = node->left;
        }
        return hght;
    }
    int findHeightRight(TreeNode *node)
    {
        int hght = 0;
        while (node)
        {
            hght++;
            node = node->right;
        }
        return hght;
    }
};

int main()
{
    createTreeNode();
    Solution s1;

    cout << s1.countNodes(root);

    return 0;
}
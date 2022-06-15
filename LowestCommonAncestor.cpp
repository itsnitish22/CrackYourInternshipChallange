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
    TreeNode *lowestCommonAncestor(TreeNode *root, int a, int b)
    {
        if (!root)
            return NULL;

        if (root->val == a || root->val == b)
            return root;

        auto l = lowestCommonAncestor(root->left, a, b);
        auto r = lowestCommonAncestor(root->right, a, b);

        if (l && r)
            return root;

        if (l == NULL && r != NULL)
            return r;
        if (l != NULL && r == NULL)
            return l;

        return NULL;
    }
};

int main()
{
    createTreeNode();
    Solution s1;

    auto ans = s1.lowestCommonAncestor(root, 4, 7);
    cout << ans->val;

    return 0;
}
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        getRightViewBT(root, 0, ans);

        return ans;
    }

    void getRightViewBT(TreeNode *root, int level, vector<int> &ans)
    {
        if (!root)
            return;

        if (level == ans.size())
            ans.push_back(root->val);

        getRightViewBT(root->right, level + 1, ans);
        getRightViewBT(root->left, level + 1, ans);
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    auto ans = s1.rightSideView(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
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
    vector<int> rootToNodePath(TreeNode *root, int target)
    {
        vector<int> ans;
        rootToNodePathHelper(root, target, ans);
        return ans;
    }

    bool rootToNodePathHelper(TreeNode *root, int target, vector<int> &ans)
    {
        if (!root)
            return false;

        ans.push_back(root->val);

        if (root->val == target)
            return true;

        bool l = rootToNodePathHelper(root->left, target, ans);
        bool r = rootToNodePathHelper(root->right, target, ans);

        if (l || r)
            return true;

        ans.pop_back();

        return false;
    }
};

int main()
{
    createTreeNode();
    Solution s1;

    auto ans = s1.rootToNodePath(root, 7);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
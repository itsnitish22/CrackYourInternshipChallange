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
    vector<int> printBoundary(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        if (!isLeaf(root))
            ans.push_back(root->val);

        getLeftBound(root, ans);
        getLeafBound(root, ans);
        getRightBound(root, ans);
    }

    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }

    void getLeftBound(TreeNode *root, vector<int> &ans)
    {
        TreeNode *node = root->left;

        while (node)
        {
            if (!isLeaf(node))
                ans.push_back(node->val);
            if (node->left)
                node = node->left;
            else
                node = node->right;
        }
    }
    void getLeafBound(TreeNode *root, vector<int> &ans)
    {
        if (isLeaf)
        {
            ans.push_back(root->val);
            return;
        }

        if (root->left)
            getLeafBound(root->left, ans);
        if (root->right)
            getLeftBound(root->right, ans);
    }
    void getRightBound(TreeNode *root, vector<int> &ans)
    {
        TreeNode *node = root->right;
        stack<int> tempAns;
        while (node)
        {
            if (!isLeaf(node))
                tempAns.push(node->val);
            if (node->right)
                node = node->right;
            else
                node = node->left;
        }

        while (!tempAns.empty())
        {
            int temp = tempAns.top();
            tempAns.pop();
            ans.push_back(temp);
        }
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    auto ans = s1.printBoundary(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
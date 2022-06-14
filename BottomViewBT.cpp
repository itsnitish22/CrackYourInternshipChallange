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
    vector<int> bottomView(TreeNode *root)
    {
        vector<int> finalAns;
        if (!root)
            return finalAns;

        queue<pair<TreeNode *, int>> addr;
        map<int, int> ans;

        addr.push({root, 0});

        while (!addr.empty())
        {
            auto front = addr.front();
            addr.pop();

            TreeNode *node = front.first;
            int level = front.second;

            ans[level] = node->val;

            if (node->left)
                addr.push({node->left, level - 1});
            if (node->right)
                addr.push({node->right, level + 1});
        }

        for (auto it : ans)
        {
            finalAns.push_back(it.second);
        }

        return finalAns;
    }
};

int main()
{
    createTreeNode();
    Solution s1;

    auto ans = s1.bottomView(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> finalAns;
        if (!root)
            return finalAns;

        queue<pair<TreeNode *, pair<int, int>>> nodesTraversal;
        map<int, map<int, multiset<int>>> mappedAns;

        nodesTraversal.push({root, {0, 0}});
        while (!nodesTraversal.empty())
        {
            auto front = nodesTraversal.front();
            nodesTraversal.pop();

            TreeNode *node = front.first;
            int vertical = front.second.first;
            int level = front.second.second;

            mappedAns[vertical][level].insert(node->val);

            if (node->left)
                nodesTraversal.push({node->left, {vertical - 1, level + 1}});
            if (node->right)
                nodesTraversal.push({node->right, {vertical + 1, level + 1}});
        }

        for (auto it : mappedAns)
        {
            vector<int> cols;
            for (auto ti : it.second)
            {
                cols.insert(cols.end(), ti.second.begin(), ti.second.end());
            }
            finalAns.push_back(cols);
        }

        return finalAns;
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    auto ans = s1.verticalTraversal(root);

    for (auto it : ans)
    {
        for (auto ti : it)
        {
            cout << ti << " ";
        }
    }
    return 0;
}
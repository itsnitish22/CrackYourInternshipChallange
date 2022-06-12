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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> finalAns;
        if (!root)
            return finalAns;

        queue<TreeNode *> addresses;
        addresses.push(root);

        int flag = true;

        while (!addresses.empty())
        {
            int size = addresses.size();
            vector<int> tempAns;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = addresses.front();
                tempAns.push_back(front->val);
                addresses.pop();

                if (front->left)
                {
                    addresses.push(front->left);
                }
                if (front->right)
                {
                    addresses.push(front->right);
                }
            }

            if (flag)
            {
                finalAns.push_back(tempAns);
                flag = false;
            }
            else
            {
                reverse(tempAns.begin(), tempAns.end());
                finalAns.push_back(tempAns);
                flag = true;
            }
        }
        return finalAns;
    }
};

int main()
{
    createTreeNode();
    Solution s1;
    auto ans = s1.zigzagLevelOrder(root);

    for (auto it : ans)
    {
        for (auto ti : it)
        {
            cout << ti << " ";
        }
    }

    return 0;
}
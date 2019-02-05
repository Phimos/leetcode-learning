/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* copyTree(TreeNode* root, int delta = 0)
    {
        if (root == NULL)
            return NULL;
        TreeNode* newroot = new TreeNode(root->val + delta);
        if (root->left)
            newroot->left = copyTree(root->left, delta);
        if (root->right)
            newroot->right = copyTree(root->right, delta);
        return newroot;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*> > Trees(n + 1);
        Trees[0].push_back(NULL);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                for (int kl = 0; kl < Trees[j].size(); ++kl)
                {
                    for (int kr = 0; kr < Trees[i - 1 - j].size(); ++kr)
                    {
                        TreeNode* root = new TreeNode(j + 1);
                        root->left = copyTree(Trees[j][kl]);
                        root->right = copyTree(Trees[i - 1 - j][kr], root->val);
                        Trees[i].push_back(root);
                    }
                }
            }
        }
        Trees[0].clear();
        return Trees[n];
    }
};
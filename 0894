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
    TreeNode* copyTree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        TreeNode* newroot = new TreeNode(0);
        if (root->left)
            newroot->left = copyTree(root->left);
        if (root->right)
            newroot->right = copyTree(root->right);
        return newroot;
    }
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<vector<TreeNode*> > FBTs(N + 1);
        FBTs[0].push_back(NULL);
        for (int i = 1; i <= N; ++i)
        {
            if (i % 2 == 0)
                continue;
            for (int j = 0; j < i; ++j)
            {
                for (int kl = 0; kl < FBTs[j].size(); ++kl)
                {
                    for (int kr = 0; kr < FBTs[i - 1 - j].size(); ++kr)
                    {
                        TreeNode* root = new TreeNode(0);
                        root->left = copyTree(FBTs[j][kl]);
                        root->right = copyTree(FBTs[i - 1 - j][kr]);
                        FBTs[i].push_back(root);
                    }
                }
            }
        }
        return FBTs[N];
    }
};
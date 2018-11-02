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
public:
	int diameter;
	int lrd(TreeNode* root, int depth)
	{
		if (!root)
			return 0;
		int lpath = lrd(root->left, depth + 1);
		int rpath = lrd(root->right, depth + 1);
		int maxpath = max(lpath, rpath);
		diameter = max(diameter, max(lpath + rpath, maxpath + depth));
		return maxpath + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		diameter = 0;
		lrd(root, 0);
		return diameter;
	}
};
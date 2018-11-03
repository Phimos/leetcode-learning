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
	TreeNode* newRoot, * pre;
	void buildIncreasing(TreeNode* root)
	{
		if (!root)
			return;
		buildIncreasing(root->left);
		if (!pre)
		{
			newRoot = pre = root;
		}
		else
		{
			pre->right = root;
			pre = root;
			root->left = NULL;
		}
		buildIncreasing(root->right);
	}
	TreeNode* increasingBST(TreeNode* root) {
		newRoot = pre = NULL;
		buildIncreasing(root);
		return newRoot;
	}
};
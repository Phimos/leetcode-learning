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
	int sum;
	void ldr(TreeNode* root, bool isleft)
	{
		if (!root)
			return;
		if (!root->left && !root->right)
		{
			if (isleft)
				sum += root->val;
			return;
		}
		ldr(root->left, true);
		ldr(root->right, false);
	}

	int sumOfLeftLeaves(TreeNode* root) {
		sum = 0;
		ldr(root, false);
		return sum;
	}
};
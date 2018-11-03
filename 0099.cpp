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
	TreeNode* pre, * leftNode, * rightNode;
	void ldr(TreeNode* root, bool& stop)
	{
		if (!root || stop)
			return ;
		else
		{
			ldr(root->left, stop);
			if (!pre)
			{
				pre = root;
			}
			else
			{
				if (pre->val > root->val)
				{
					leftNode = pre;
					stop = true;
					return;
				}
				else
				{
					pre = root;
				}
			}
			ldr(root->right, stop);
		}
	}
	void rdl(TreeNode* root, bool& stop)
	{
		if (!root || stop)
			return ;
		else
		{
			rdl(root->right, stop);
			if (!pre)
			{
				pre = root;
			}
			else
			{
				if (pre->val < root->val)
				{
					rightNode = pre;
					stop = true;
					return;
				}
				else
				{
					pre = root;
				}
			}
			rdl(root->left, stop);
		}
	}
	void recoverTree(TreeNode* root) {
		bool mark;
		mark = false;
		pre = NULL;
		ldr(root, mark);
		mark = false;
		pre = NULL;
		rdl(root, mark);
		swap(leftNode->val, rightNode->val);
		return;
	}
};
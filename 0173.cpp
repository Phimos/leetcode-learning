/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	stack<TreeNode*> nodeStack;

	BSTIterator(TreeNode *root) {
		while (root)
		{
			nodeStack.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !nodeStack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* temp = nodeStack.top();
		nodeStack.pop();
		int val = temp.val;
		temp = temp->right;
		while (temp)
		{
			nodeStack.push(temp);
			temp = temp->left;
		}
		return val;
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
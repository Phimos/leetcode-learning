class Solution {
public:
	vector<vector<string>> TreeString;
	int h;
	int getDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		else
			return max(getDepth(root->left), getDepth(root->right)) + 1;
	}

	void buildTree(TreeNode* root, int depth, int startX)
	{
		if (!root)
			return;
		int x = startX - 1 + (1 << (h - depth - 1));
		TreeString[depth][x] = to_string(root->val);
		buildTree(root->left, depth + 1, startX);
		buildTree(root->right, depth + 1, x + 1);
	}

	vector<vector<string>> printTree(TreeNode* root) {
		h = getDepth(root);
		TreeString.resize(h, vector<string>((1 << h) - 1));
		buildTree(root, 0, 0);
		return TreeString;
	}
};
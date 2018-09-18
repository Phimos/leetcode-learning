class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.length() + 1;
		int len2 = word2.length() + 1;
		int **path = new int *[len1];
		if (!path)
			return 0;
		for (int i = 0; i < len1; ++i)
		{
			path[i] = new int[len2];
			if (!path[i])
				return 0;
		}
		//初始化
		//path[i][j]代表从word1的前i个字符转换为word2的前j个字符所需要的步数
		for (int i = 0; i < len1; ++i)
			path[i][0] = i;
		for (int j = 0; j < len2; ++j)
			path[0][j] = j;
		for (int i = 1; i < len1; ++i)
		{
			for (int j = 1; j < len2; ++j)
			{
				int temp1;//通过替换word1的第i个为word2的第j个
				temp1 = (word1[i - 1] == word2[j - 1] ? 0 : 1) + path[i - 1][j - 1];
				int temp2;//通过增加或减少
				temp2 = 1 + min(path[i][j - 1], path[i - 1][j]);
				path[i][j] = min(temp1, temp2);
			}
		}
		return path[len1-1][len2-1];
	}
};
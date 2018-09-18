class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size(), maxarea = 0;
		for (int l = 0, r = n - 1;l<r;)
		{
			maxarea = max(maxarea, min(height[l], height[r])*(r - l));
			if (height[l] < height[r])
				++l;
			else
				--r;
		}
		return maxarea;
	}
};

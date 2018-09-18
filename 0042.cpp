class Solution {
public:
	int trap(vector<int>& height) {
		int lmax = 0,rmax=0;//左侧最大高度
		int sum=0, temp=0;
		for (int h : height)
		{
			if (h >= lmax)
			{
				sum += temp;
				temp = 0;
				lmax = h;
			}
			else
			{
				temp += lmax - h;
			}
		}
		temp = 0;
		for (int i=height.size()-1;i>=0;--i)
		{
			if (height[i] > rmax)
			{
				sum += temp;
				temp = 0;
				rmax = height[i];
				if (rmax == lmax)
					break;
			}
			else
			{
				temp += rmax - height[i];
			}
		}
		return sum;
	}
};
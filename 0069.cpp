class Solution {
public:
	int mySqrt(int x) {
		int left=0,right=min(x,46340),mid,ans;////46340*46340<INT_MAX,46341*46341>INT_MAX
		while(left<=right)
		{
			mid=left+(right-left)/2;
			if(mid*mid>x)
				right=mid-1;
			else
			{
				ans=mid;
				left=mid+1;
			}
		}
		return ans;
	}
};
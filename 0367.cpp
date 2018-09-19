class Solution {
public:
	bool isPerfectSquare(int num) {
		int left=1,right=min(num,46340),mid;//46340*46340<INT_MAX,46341*46341>INT_MAX
		while(left<=right)
		{
			int mid=left+(right-left)/2;
			if(mid*mid==num)
				return true;
			else if(mid*mid<num)
				left=mid+1;
			else
				right=mid-1;
		}
		return false;
	}
};
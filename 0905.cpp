class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int left=0,right=A.size()-1;
		while(left<right)
		{
			while(!(A[left]&1))//找到左侧第一个奇数
				++left;
			while(A[right]&1)//找到右侧第一个偶数
				--right;
			if(left<right)
				swap(A[left],A[right]);
		}
		return A;
	}
};
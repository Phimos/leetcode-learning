class NumArray {
	vector<int> Arr;
	vector<int> num;
	int n;
public:
	int lowbit(int k)
	{
		return k & (-k);
	}

	NumArray(vector<int> nums) {
		num = nums;
		n = nums.size();
		vector<int> temp;
		temp.push_back(0);
		for (int i = 0; i < n; ++i)
		{
			temp.push_back(temp.back() + nums[i]);
		}
		Arr.resize(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			Arr[i] = temp[i] - temp[i - lowbit(i)];
		}
	}


	void update(int i, int val) {
		int delta = val - num[i];
		num[i] = val;
		++i;
		for (; i <= n; i += lowbit(i))
			Arr[i] += delta;
	}

	int getSum(int k)
	{
		int sum = 0;
		for (int i = k; i > 0; i -= lowbit(i))
			sum += Arr[i];
		return sum;
	}

	int sumRange(int i, int j) {
		return getSum(j + 1) - getSum(i);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
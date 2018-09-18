class Solution {
public:
	int find_point(vector<int>& nums, int l, int r)
	{
		if (l >= r)
			return l;
		int mid = (l + r) / 2;
		if (nums[mid] > nums[0])
			return find_point(nums, mid+1, r);
		else
			return find_point(nums, l, mid);
	}
	int binary_search(vector<int>& nums,int target, int l, int r)
	{
		if (l >= r)
		{
			if (nums[l] == target)
				return l;
			else
				return -1;
		}
		int mid = (l + r) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			return binary_search(nums, target, l, mid);
		else
			return binary_search(nums, target, mid + 1, r);
	}
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		int k = find_point(nums, 0, nums.size());
		if (nums[0] > target)
			return binary_search(nums, target, k, nums.size());
		else
			return binary_search(nums, target, 0, k);
	}
}; 

class Solution {
private:
	vector<vector<int>> combination;
	void combine(vector<int>& candidates, int target,int k,vector<int>& nums,int sum)
	{
		if (sum == target)
			combination.push_back(nums);
		else if(sum<target)
		{
			for (int i = k; i < candidates.size(); ++i)
			{
				if (target - sum < candidates[i])
					continue;
				else
				{
					nums.push_back(candidates[i]);
					combine(candidates, target, i, nums, sum + candidates[i]);
					nums.pop_back();
				}
			}
		}
		return;
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> nums;
		combine(candidates, target, 0, nums, 0);
		return combination;
	}
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  		map<int,int> check;
		vector<int> ans;
		for (int i=0;i<nums.size();++i)
		{
			if (check.count(target - nums[i]))
			{
				ans.push_back(check[target - nums[i]]);
				ans.push_back(i);
				return ans;
			}
			else
				check[nums[i]] = i;
		}
		return ans;
    }
};
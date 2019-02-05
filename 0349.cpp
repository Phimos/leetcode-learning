class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> temp(nums2.begin(), nums2.end());
		set<int> ans;
		for (auto num : nums1)
			if (temp.find(num) != temp.end())
				ans.insert(num);
		return vector<int>(ans.begin(), ans.end());
	}
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<string>();
        vector<pair<int, int>> temp;
        vector<string> ans;
        temp.push_back(make_pair(nums[0], nums[0]));
        for (int i = 1; i < nums.size(); ++i)
        {
            if (temp.back().second + 1 == nums[i])
                temp.back().second++;
            else
                temp.push_back(make_pair(nums[i], nums[i]));
        }
        for (int i = 0; i < temp.size(); ++i)
        {
            if (temp[i].first == temp[i].second)
                ans.push_back(to_string(temp[i].first));
            else
                ans.push_back(to_string(temp[i].first) + "->" + to_string(temp[i].second));
        }
        return ans;
    }
};
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string,vector<string>> dict;
		for (auto str : strs)
		{
			string ori_str = str;
			sort(str.begin(), str.end());
			dict[str].push_back(ori_str);
		}
		vector<vector<string>> ans;
		for (auto page : dict)
		{
			ans.push_back(page.second);
		}
		return ans;
	}
};
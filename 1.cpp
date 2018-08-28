#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> check;
		vector<int> ans;
		for (int i = 0; i<nums.size(); ++i)
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
class Solution {
	vector<vector<int>> res;
	void get_permutation(vector<int>& nums,vector<int>& ans,int k)
	{
		if(k==nums.size())
			res.push_back(ans);
		else
		{
			for(int i=0;i<nums.size();++i)
			{
				bool used=false;
				for(int j=0;j<k;++j)
				{
					if(nums[i]==ans[j])
					{
						used=true;
						break;
					}
				}
				if(!used)
				{
					ans.push_back(nums[i]);
					get_permutation(nums,ans,k+1);
					ans.pop_back();
				}
			}
		}
	}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        get_permutation(nums,ans,0);
        return res;
    }
};
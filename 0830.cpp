class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		int s=0,e=0;
		vector<vector<int>> res;
		int l=S.length();
		S.push_back(0);//保证最末端的较大分组能够被收入res
		for(int i=0;i<=l;++i)
		{
			if(S[i]==S[s])
				e=i;
			else
			{
				if(e-s>=2)
					res.push_back(vector<int>{s,e});
				s=e=i;
			}
		}
		return res;
	}
};
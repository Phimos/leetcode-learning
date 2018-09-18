/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp_intervals(Interval& a, Interval& b)
	{
		return a.start < b.start;
	}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp_intervals);
		vector<Interval> ans;
		if (intervals.size() == 0)
			return ans;
		Interval temp = intervals[0];
		for (int i = 0; i < intervals.size() - 1; ++i)
		{
			if (intervals[i + 1].start <= temp.end)
				temp.end = max(intervals[i + 1].end, temp.end);
			else
			{
				ans.push_back(temp);
				temp = intervals[i + 1];
			}
		}
		ans.push_back(temp);
		return ans;
	}
}; 
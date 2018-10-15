class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map<char, int> tasksList;
		for (int i = 0; i < tasks.size(); ++i)
		{
			if (tasksList.count(tasks[i]))
				++tasksList[tasks[i]];
			else
				tasksList[tasks[i]] = 1;
		}
		int CommonTaskNum = 0, times = 0, sum = 0;
		int TaskKind = tasksList.size();
		for (auto i : tasksList)
		{
			sum += i.second;
			if (i.second > times)
			{
				CommonTaskNum = 1;
				times = i.second;
			}
			else if (i.second == times)
				++CommonTaskNum;
		}
		return max(sum - CommonTaskNum, (n + 1) * (times - 1)) + CommonTaskNum;
	}
};
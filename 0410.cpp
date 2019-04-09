class Solution {
public:
    bool check(vector<int>& nums, int m, long long s)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > s || m == 0)
                return false;
            if (sum + nums[i] > s)
            {
                sum = nums[i];
                --m;
            }
            else
                sum += nums[i];
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        nums.push_back(0);
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        long long left = sum / m, right = sum;
        while (left < right)
        {
            long long mid = (left + right) >> 1;
            if (check(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
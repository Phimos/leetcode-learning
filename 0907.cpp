class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        long mod = 1e9 + 7;
        long res = 0, ans = 0;
        vector<int>p, q;
        for (int i = 0; i < n; ++i)
        {
            int count = 1;
            while (!p.empty() && p.back() > A[i])
            {
                ans = (ans - p.back() * q.back() % mod + mod) % mod;
                p.pop_back();
                count += q.back(); //左侧一段的集合总数
                q.pop_back();
            }
            p.push_back(A[i]);
            q.push_back(count);
            ans = (ans + A[i] * count % mod) % mod;
            res = (res + ans) % mod;
        }
        return (int)res;
    }
};

//最早代码
class Solution {
public:
    long long get_sumSubarraymin(vector<int>& A, int left, int right)
    {
        if (left == right)
            return 0;
        int array_min = 0x7fffffff, pos_min = -1;
        for (int i = left; i < right; ++i)
        {
            if (A[i] < array_min)
            {
                pos_min = i;
                array_min = A[i];
            }
        }
        long long ans = array_min;
        ans = (ans * ((pos_min - left + 1) % 1000000007)) % 1000000007;
        ans = (ans * ((right - pos_min) % 1000000007)) % 1000000007;
        return (ans + get_sumSubarraymin(A, left, pos_min) + get_sumSubarraymin(A, pos_min + 1, right)) % 1000000007;
    }
    int sumSubarrayMins(vector<int>& A) {
        return get_sumSubarraymin(A, 0, A.size());
    }
};
class Solution {
public:
    struct NUM
    {
        int n, pos;
        NUM() {}
        NUM(int n, int pos): n(n), pos(pos) {}
        bool operator<(const NUM& b)const
        {
            if(n!=b.n)
            return n<b.n;
            else
                return pos>b.pos;
        }
    };
    int n;
    vector<int> Arr;
    int lowbit(int k)
    {
        return k & (-k);
    }
    void update(int k)
    {
        for (int i = k; i <= n; i += lowbit(i))
        {
            Arr[i] += 1;
        }
    }
    int getSum(int k)
    {
        int ans = 0;
        for (int i = k; i > 0; i -= lowbit(i))
        {
            ans += Arr[i];
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        vector<NUM> temp;
        Arr.resize(n+1,0);
        for (int i = 0; i < n; ++i)
        {
            temp.push_back(NUM(nums[i], i + 1));	//+1防止i为0
        }
        sort(temp.begin(), temp.end());
        int slow = 0, fast = 0, res = 0;
        for (; fast < n; ++fast)
        {
            while (slow < n &&  temp[slow].n < temp[fast].n-temp[slow].n)
            {
                update(temp[slow].pos);
                ++slow;
            }
            res += slow - getSum(temp[fast].pos);
        }
        return res;
    }
};

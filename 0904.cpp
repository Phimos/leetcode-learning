class Solution {
public:
    int totalFruit(vector<int>& tree) {
        deque<int> basket;
        int maxlen = 0, len = 0, ans = 0;
        for (int i = 0; i < tree.size(); ++i)
        {
            if (basket.size() == 0)
            {
                basket.push_back(tree[i]);
                ++maxlen;
            }
            else if (basket.size() == 1)
            {
                if (tree[i] == basket[0])
                {
                    ++maxlen;
                }
                else
                {
                    basket.push_back(tree[i]);
                    ++maxlen;
                    len = 1;
                }
            }
            else
            {
                if (tree[i] == basket[0])
                {
                    swap(basket[0], basket[1]);
                    ++maxlen;
                    len = 1;
                }
                else if (tree[i] == basket[1])
                {
                    ++maxlen;
                    ++len;
                }
                else
                {
                    ans = max(maxlen, ans);
                    maxlen = len + 1;
                    len = 1;
                    basket[0] = basket[1];
                    basket[1] = tree[i];
                }
            }
        }
        ans = max(maxlen, ans);
        return ans;
    }
};
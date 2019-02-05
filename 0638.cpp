class Solution {
    bool isValid(vector<int>& offer, vector<int>& needs)
    {
        for (int i = 0; i < needs.size(); ++i)
            if (needs[i] < offer[i])
                return false;
        return true;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int money = 0;
        for (int i = 0; i < needs.size(); ++i)
            money += needs[i] * price[i];
        for (int i = 0; i < special.size(); ++i)
        {
            if (isValid(special[i], needs))
            {
                for (int j = 0; j < needs.size(); ++j)
                {
                    needs[j] -= special[i][j];
                }
                money = min(money, shoppingOffers(price, special, needs) + special[i].back());
                for (int j = 0; j < needs.size(); ++j)
                {
                    needs[j] += special[i][j];
                }
            }
        }
        return money;
    }
};
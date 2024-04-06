// https://leetcode.com/problems/coin-change/submissions/1085960746/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, amount + 1);

        f[0] = 0;

        for (int i = 1; i < f.size(); i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i >= coins[j])
                    f[i] = min(f[i], 1 + f[i - coins[j]]);
            }
        }
        if (f[amount] == amount+1)
            return -1;

        return f[amount];
    }
};
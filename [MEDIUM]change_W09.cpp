//https://leetcode.com/problems/coin-change-ii/submissions/1091929570/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int* f = new int[amount+1] {0};

        f[0] = 1;

        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
               f[j] += f[j - coins[i]]; 
            }
        }

        return f[amount];
    }
};
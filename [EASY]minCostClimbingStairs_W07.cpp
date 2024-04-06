// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1085239585/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int* f = new int[cost.size()+1];

        f[0] = 0;
        f[1] = 0;
        for (int i = 2; i < cost.size()+1; i++)
            f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);

        return f[cost.size()];
    }
};
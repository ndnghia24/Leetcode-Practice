// https://leetcode.com/problems/target-sum/submissions/1093433105/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += abs(num);
        }

        int len = nums.size();
        int range = sum * 2 + 1;

        int** dp = new int*[len+1];
        for (int i = 0; i < len+1; i++)
            dp[i] = new int[range] {0};

        dp[0][sum] = 1;

        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < range; ++j) {
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
                if (j + nums[i - 1] < range) {
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
                }
            }
        }

        int targetIndex = target + sum;
        return (targetIndex >= 0 && targetIndex < range) ? dp[len][targetIndex] : 0;
}
};
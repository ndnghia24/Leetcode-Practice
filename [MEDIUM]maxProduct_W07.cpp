// https://leetcode.com/problems/maximum-product-subarray/submissions/1085989721/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> maxDP(n);
        vector<int> minDP(n);

        maxDP[0] = nums[0];
        minDP[0] = nums[0];
        int max_product = nums[0];

        for (int i = 1; i < n; i++) {
            maxDP[i] = max({nums[i], maxDP[i - 1] * nums[i], minDP[i - 1] * nums[i]});
            minDP[i] = min({nums[i], maxDP[i - 1] * nums[i], minDP[i - 1] * nums[i]});

            max_product = max(max_product, maxDP[i]);
        }

        return max_product;
    }
};
// https://leetcode.com/problems/two-sum/submissions/1057983962/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> pos;

        for (int i = 0; i < nums.size(); i++) {
            if (pos.find(target - nums[i]) != pos.end())
                return {pos[target - nums[i]], i};
            pos.insert({nums[i], i});
        }

        return {};
    }
};
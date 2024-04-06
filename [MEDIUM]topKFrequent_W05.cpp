// https://leetcode.com/problems/top-k-frequent-elements/submissions/1057988340/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums)
            counts[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto count : counts)
            buckets[count.second].push_back(count.first);
        
        vector<int> res;
        for (int i = nums.size(); i > 0; --i) {
            for (int j : buckets[i]) {
                res.push_back(j);
                if (res.size() == k)
                    return res;
            }      
        }
        return res;
    }
};
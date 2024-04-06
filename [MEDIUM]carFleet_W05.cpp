//https://leetcode.com/problems/car-fleet/submissions/1063943955/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> mergeArr(position.size());

        for (int i = 0; i < position.size(); i++) 
            mergeArr[i] = {position[i], float(target - position[i])/ speed[i]};
        
        sort(mergeArr.begin(), mergeArr.end());
        int frontFleet = mergeArr.size()-1;
        int countFleets = 1;

        for (int i = mergeArr.size()-2; i >= 0; i--) {
            if (frontFleet > 0 && mergeArr[i].second <= mergeArr[frontFleet].second)
                continue;
            else
                countFleets++;
            frontFleet = i;
        }
        return countFleets;
    }
};
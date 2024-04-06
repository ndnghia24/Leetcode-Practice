// https://leetcode.com/problems/group-anagrams/submissions/1057253737/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams2D;
        
        char count[26];
        char clone[26];

        for (string str : strs) {
            bool isAdded = false;

            memset(count, 0, sizeof(char)*26);
            for (char ch : str) {
                count[ch - 'a']++;
            }

            for (int i = 0; i < anagrams2D.size(); i++) {
                bool check1D = true;
                memcpy(clone, count, sizeof(char)*26);

                if (anagrams2D.size() == 0) {
                    anagrams2D.push_back({str});
                    break;
                }
                
                for (char ch : anagrams2D[i][0]) {
                    clone[ch - 'a']--;
                }
                
                for (int i = 0; i < 26; i++) {
                    if (clone[i] != 0)
                        check1D = false;
                }
                if (check1D == true) {
                    anagrams2D[i].push_back(str);
                    isAdded = true;
                    break;
                }
            }
            if (!isAdded)
                anagrams2D.push_back({str});
        }
        return anagrams2D;
    }
};
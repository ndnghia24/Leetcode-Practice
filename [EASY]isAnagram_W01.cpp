// https://leetcode.com/problems/valid-anagram/submissions/1057981090/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int counter[26];
        memset(counter, 0, sizeof(int)*26);

        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (counter[i] != 0)
                return false;

        return true;
    }
};
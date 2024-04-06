// https://leetcode.com/problems/decode-ways/submissions/1085915602/

class Solution {
public:
    int numDecodings(string s) {
        int* f = new int[s.size()+1];

        f[0] = f[1] = 1;

        if (s[0] == '0')
            return 0;

        for (int i = 2; i <= s.size(); i++) {
            if (s[i-1] != '0') 
            {
                if (stoi(s.substr(i-2, 2)) < 27 && stoi(s.substr(i-2, 2)) > 0 && s[i-2] != '0')
                    f[i] = f[i-1] + f[i-2];
                else
                    f[i] = f[i-1];
            }
            else
            {
                if (stoi(s.substr(i-2, 2)) < 27 && stoi(s.substr(i-2, 2)) > 0 && s[i-2] != '0')
                    f[i] = f[i-2];
                else
                    f[i] = 0;
            }

        }
        
        return f[s.size()];
    }
};
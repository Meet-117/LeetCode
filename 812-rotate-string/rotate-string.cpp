class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i = 0; i < s.length(); i++) {
            string res = s[s.length() - 1] + s.substr(0, s.length() - 1);
            if (res == goal) {
                return true;
            }
            s = res;
        }
        return false;
    }
};
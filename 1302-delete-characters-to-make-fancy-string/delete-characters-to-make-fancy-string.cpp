class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;
        result += s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] == s[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count < 3) {
                result += s[i];
            }
        }
        return result;
    }
};
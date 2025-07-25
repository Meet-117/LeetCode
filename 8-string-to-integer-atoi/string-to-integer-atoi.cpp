class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0;
        bool isNeg = false;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i == s.length()) return 0;

        if (s[i] == '-') {
            isNeg = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long result = 0;

        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (!isNeg && result > INT_MAX) return INT_MAX;
            if (isNeg && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return isNeg ? -result : result;
    }
};

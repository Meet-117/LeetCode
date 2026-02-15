class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                int n = a[i] - '0';
                sum += n;
                i--;
            }
            if (j >= 0) {
                int m = b[j] - '0';
                sum += m;
                j--;
            }
            char c = (sum % 2) + '0';
            ans += c;
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
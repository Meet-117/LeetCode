class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string s1E = "";
        string s1O = "";
        string s2E = "";
        string s2O = "";

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                s1E += s1[i];
                s2E += s2[i];
            } else {

                s1O += s1[i];
                s2O += s2[i];
            }
        }
        sort(s1E.begin(), s1E.end());
        sort(s1O.begin(), s1O.end());
        sort(s2E.begin(), s2E.end());
        sort(s2O.begin(), s2O.end());

        if (s1E == s2E && s1O == s2O) {
            return true;
        }
        return false;
    }
};
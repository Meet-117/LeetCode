class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3)
            return false;
        string vowels = "aeiouAEIOU";
        int vowel = 0, consonant = 0;
        for (int i = 0; i < word.length(); i++) {
            if (!isalnum(word[i])) {
                return false;
            }
            if (isalpha(word[i])) {
                if (vowels.find(word[i]) != string::npos) {
                    vowel++;
                } else {
                    consonant++;
                }
            }
        }
        if (vowel >= 1 && consonant >= 1) {
            return true;
        }
        return false;
    }
};
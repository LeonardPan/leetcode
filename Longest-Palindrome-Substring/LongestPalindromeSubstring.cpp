const unsigned int MAX_LENGTH = 1001;

bool palindromeTable[MAX_LENGTH][MAX_LENGTH];

class Solution {
public:
    void init(bool(&input)[MAX_LENGTH][MAX_LENGTH]) {
        memset(&input, 0, MAX_LENGTH * MAX_LENGTH);
    }
    string longestPalindrome(string s) {
        init(palindromeTable);
        unsigned int maxLength = 1;
        unsigned int startIndex = 0;
        unsigned int length = s.size();
        //for each length of substring
        for (int len = 1; len <= length; ++len) {
            for (int i = 0; i < length; ++i) {
                if (len == 1) {
                    //every single char is a valid palindrome
                    palindromeTable[i][i] = true;
                }
                else if (len == 2 && i + 1 < length) {
                    palindromeTable[i][i + 1] = (s[i] == s[i + 1]);
                    if (palindromeTable[i][i + 1] && 2 > maxLength) {
                        maxLength = 2;
                        startIndex = i;
                    }
                }
                else if (i + len - 1 < length) {
                    //whether s[i, i + len - 1] is a palindrome substring? It depends on s[i + 1, i + len - 2] and itself
                    palindromeTable[i][i + len - 1] = (palindromeTable[i + 1][i + len - 2] && s[i] == s[i + len - 1]);
                    if (palindromeTable[i][i + len - 1] && len > maxLength) {
                        maxLength = len;
                        startIndex = i;
                    }
                }
            }
        }
        return s.substr(startIndex, maxLength);
    }
};

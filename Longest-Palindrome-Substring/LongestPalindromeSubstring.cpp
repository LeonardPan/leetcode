class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        string longestStr;
        for (size_t i = 0; i < length; ++i)
        {
            if ((i + 1) * 2 < longestStr.size()) {
                break;
            }
            //treat [i] as the center of the paradrome
            string currentStr = string(1, s[i]);
            if (longestStr.size() < 1) {
                longestStr = currentStr;
            }
            for (int left = i - 1, right = i + 1;
                left >= 0 && right < length;
                --left, ++right)
            {
                //valid paradrome string
                if (s[left] == s[right])
                {
                    currentStr = s[left] + currentStr + s[right];
                    if (currentStr.size() > longestStr.size()) {
                        longestStr = currentStr;
                    }
                }
                //invalid paradrome string
                else {
                    break;
                }
            }
            if (i < length - 1 && s[i] == s[i + 1]) {
                //treat [i, i+1] as the center of the paradrome
                currentStr = string(1, s[i]) + s[i + 1];
                if (longestStr.size() < 2) {
                    longestStr = currentStr;
                }
                for (int left = i - 1, right = i + 2;
                    left >= 0 && right < length;
                    --left, ++right)
                {
                    //valid paradrome string
                    if (s[left] == s[right])
                    {
                        currentStr = s[left] + currentStr + s[right];
                        if (currentStr.size() > longestStr.size()) {
                            longestStr = currentStr;
                        }
                    }
                    //invalid paradrome string
                    else {
                        break;
                    }
                }
            }
        }
        return longestStr;
    }
};

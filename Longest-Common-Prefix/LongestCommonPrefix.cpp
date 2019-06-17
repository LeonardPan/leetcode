class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = strs.size();
        if (count == 0) {
            return "";
        }
        else if (count == 1) {
            return strs[0];
        }
        char c = -1;
        string outputStr;
        for(int j = 0; c != 0; ++j) {
            for(int i = 0; i < count; ++i) {
                if(i == 0) {
                    c = strs[i][j];
                } else {
                    char d = strs[i][j];
                    if(d == 0) {
                        return outputStr;
                    } else if(c != d) {
                        return outputStr;
                    }
                }
            }
            outputStr += c;
        }
        return outputStr;
    }
};

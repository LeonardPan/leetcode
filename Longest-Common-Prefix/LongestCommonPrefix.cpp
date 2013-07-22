//longest common prefix
//Author: Leonard Pan

// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(0 == strs.size())
            return string("");
        if(1 == strs.size())
            return strs[0];
        int i = 0, j = 0;
        int len1 = strs[0].length();
        bool misMatch = false;
        for(i = 0; i < len1; ++i){
            for(j = 0; j < strs.size() - 1; ++j){
                if(i >= strs[j].length() || strs[j][i] != strs[j+1][i]){
                    misMatch = true;
                    break;
                }
            }
            if(misMatch)
                break;
        }
        return 0 == i ? string("") : strs[0].substr(0, i);
    }
};

int main() {
    // Start typing your code here...
    //cout << "Hello world!" << endl;
    Solution *pSol = new Solution();
    vector<string> vecStr;
    vecStr.push_back("aa");
    vecStr.push_back("aa");
	cout << pSol->longestCommonPrefix(vecStr).c_str();
    
    return 0;
}
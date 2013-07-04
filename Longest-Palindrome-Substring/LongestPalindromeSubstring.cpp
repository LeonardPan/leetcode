//longest palindromic substring 
//Author: Leonard Pan

// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool isPalindromicStr[1010][1010];
public:
    Solution(){
        init(1010);
    }
    void init(int len){
        int i, j;
        for(i = 0; i < len; ++i)
        {
            for(j = 0; j < len; ++j)
            {
                if(i == j)
                    isPalindromicStr[i][j] = true;
                else
                    isPalindromicStr[i][j] = false;
            }
        }
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //init();
        int max_len = s.length();
        int i, longestSubstrIndex=0, longestSubstrLen=1;
        for(i = 1; i < max_len; ++i)
        {
            if(s[i] == s[i-1])
            {
                isPalindromicStr[i-1][i] = true;
                if(longestSubstrLen < 2)
                {
                    longestSubstrLen = 2;
                    longestSubstrIndex = i-1;
                }
            }  
        }
        
        int len;
        for(len = 3; len <= max_len; ++len)
        {
            for(i = 0; i <= max_len - len; ++i)
            {
                if((s[i] == s[i+len-1]) && isPalindromicStr[i+1][i+len-2])
                {
                    isPalindromicStr[i][i+len-1] = true;
                    if(longestSubstrLen < len)
                    {
                        longestSubstrLen = len;
                        longestSubstrIndex = i;
                    }
                }
            }
        }
        init(max_len);
        return s.substr(longestSubstrIndex, longestSubstrLen);
    }
};

int main() {
    // Start typing your code here...
    Solution* pSo = new Solution();
    string strIn;
    while(cin >> strIn)
    {
        if(0 == strIn.compare("exit"))
            break;
        cout << pSo->longestPalindrome(strIn) << endl;
    }
    
    return 0;
}
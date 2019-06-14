#include <stack>

class Solution {
public:
    static int _getValue(char ch) {
        switch (ch) {
                case 'I':
                    return 1;
                case 'V':
                    return 5;
                case 'X':
                    return 10;
                case 'L':
                    return 50;
                case 'C':
                    return 100;
                case 'D':
                    return 500;
                case 'M':
                    return 1000;
                default:
                    return -1;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        stack<int> stk;
        for(const auto& ch : s) {
            int value = Solution::_getValue(ch);
            if(stk.empty() || stk.top() < value) {
                stk.push(value);
            }
            else {
                int tmpValue = stk.top();
                stk.pop();
                while(!stk.empty()) {
                    tmpValue -= stk.top();
                    stk.pop();
                }
                result += tmpValue;
                stk.push(value);
            }
        }
        if(!stk.empty()) {
            int tmpValue = stk.top();
            stk.pop();
            while(!stk.empty()) {
                tmpValue -= stk.top();
                stk.pop();
            }
            result += tmpValue;
        }
        return result;
    }
};
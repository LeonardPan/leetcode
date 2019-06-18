#include <stack>
class Solution {
public:
    inline bool _isMatch(char left, char right) {
        if (left == '(' && right == ')') {
            return true;
        }
        else if (left == '{' && right == '}') {
            return true;
        }
        else if (left == '[' && right == ']') {
            return true;
        }
        return false;
    }

    //is kind of left bracket
    inline bool _isLeft(char left) {
        if (left == '(' || left == '[' || left == '{') {
            return true;
        }
        else {
            return false;
        }
    }

    bool isValid(string s) {
        int len = s.size();
        if (len == 0) {
            return true;
        }

        stack<int> stk;
        for (int i = 0; i < len; ++i) {
            //push left bracket
            if (stk.empty() || _isLeft(s[i])) {
                stk.push(s[i]);
            }
            //check the right bracket whether match the last one
            else if (_isMatch(stk.top(), s[i])) {
                stk.pop();
            }
            //not a valid parentheses if one mismatch found
            else {
                return false;
            }
        }
        //all brackets are matched in pair
        if (stk.size() == 0) {
            return true;
        }
        //at least one unmatched bracket found
        else {
            return false;
        }
    }
};

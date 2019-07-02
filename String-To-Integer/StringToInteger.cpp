class Solution {
public:
    //trim left white spaces
    string ltrim(const string& input) {
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == ' ' || input[i] == '    ' || input[i] == '\n') {
                continue;
            }
            else{
                return input.substr(i);
            }
        }
        return "";
    }
    int myAtoi(string str) {
        string trimedStr = ltrim(str);
        long long result = 0;
        bool negtive = false;
        //check negtive or not
        if (trimedStr.size() > 1) {
            if (trimedStr[0] == '-') {
                trimedStr = trimedStr.substr(1);
                negtive = true;   
            }
            else if (trimedStr[0] == '+') {
                trimedStr = trimedStr.substr(1);
            }
        }
        //travel the bytes to caculate the number
        for (const char& ch : trimedStr) {
            if (ch >= '0' && ch <= '9') {
                result = result * 10 + ch - '0';
                if (result > INT_MAX) {
                    if (negtive) {
                        return INT_MIN;
                    }
                    else {
                        return INT_MAX;
                    }
                }
            }
            else {
                break;
            }
        }
        if (negtive) {
            result = -result;
        }
        if (result > INT_MAX) {
            return INT_MAX;
        }
        else if (result < INT_MIN) {
            return INT_MIN;
        }
        else {
            return result;
        }
    }
};

#include <deque>

int decDigitalVec[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

class Solution {
public:
    int _getDigitalCount(int x) {
        int counts = 0;
        while(x != 0) {
            if(x >= 10000) {
                x /= 10000;
                counts += 4;
            }
            else if(x >= 100) {
                x /= 100;
                counts += 2;
            }
            else if(x >= 10) {
                x = 0;
                counts += 2;
            }
            else {
                x = 0;
                ++counts;
            }
        }
        return counts;
    }
    
    bool isPalindrome(int x) {
        //all negtive numbers are not palindromes
        if (x < 0) {
            return false;
        }
        //all unit numbers are palindromes
        else if (x < 10) {
            return true;
        }
        int digitalCount = _getDigitalCount(x);
        while (digitalCount > 1) {
            int topDigit = x / decDigitalVec[digitalCount - 1];
            x -= topDigit * decDigitalVec[digitalCount - 1];
            if (x % 10 != topDigit) {
                return false;
            }
            x /= 10;
            digitalCount -= 2;
        }
        return true;
    }
};

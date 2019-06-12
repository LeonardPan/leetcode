#include <limits>
class Solution {
public:
    int reverse(int x) {
        bool negtive = x < 0 ? true : false;
        long long input = negtive ? 0 - (long long)x : x;
        //OK, input is a positive number now.
        long long output = 0;
        while(input > 0) {
            int unit = input % 10;
            output = output * 10 + unit;
            input = input / 10;
        }
        output = negtive ? -output : output;
        if (output > numeric_limits<int>::max() || output < numeric_limits<int>::min()) {
            return 0;
        }
        else {
            return output;
        }
    }
};

#include <deque>
class Solution {
public:
    bool isPalindrome(int x) {
        //all negtive numbers are not palindromes
        if (x < 0) {
            return false;
        }
        //all unit numbers are palindromes
        else if (x < 10) {
            return true;
        }
        //split all digitals into a queue
        std::deque<int> q;
        while(x != 0) {
            q.push_back(x % 10);
            x /= 10;
        }
        //compare 2 digitals in each loop
        int count = q.size();
        while(count > 1) {
            //left != right, it's not a palindrome number
            if(q.front() != q.back()) {
                return false;
            }
            q.pop_front();
            q.pop_back();
            count -= 2;
        }
        //only one or zero digital left, it's a palindrome number
        return true;
    }
};

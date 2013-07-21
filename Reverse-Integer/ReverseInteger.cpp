//reverse integer
//Author: Leonard Pan

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = x < 0 ? true : false;
        long positive_x = x < 0 ? -x : x;
        long reversed_x = 0;
        while(positive_x){
            reversed_x *= 10;
            reversed_x += positive_x % 10;
            positive_x /= 10;
        }
        return neg? -reversed_x : reversed_x;
    }
};

int main()
{
	Solution *sol = new Solution();
	int integer;
	while(cin>>integer && integer != -8){
		cout << sol->reverse(integer) << endl;
	}
	return 0;
}
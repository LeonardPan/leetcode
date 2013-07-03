#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int getPower(int number)
    {
        int power = 0;
    	if(number/100000000){
    		number/=100000000;
    		power += 8;
    	}
    	if(number/10000){
    		number/=10000;
    		power += 4;
    	}
    	if(number/100){
    		number/=100;
    		power += 2;
    	}
    	if(number/10){
    		number/=10;
    		power+=1;
    	}
    	return power;
    }
    int getTopNthDigit(int number, int power, int place)
    {
    	if(place > power)
    		return -1;
    	return int((number / pow(10, double(power - place)))) % 10;
    }
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0)
            return false;
        int lMaxPower = getPower(x);
    	int lCurPos, lHighDigit, lLowDigit;
    	for(lCurPos = 0; lCurPos < (lMaxPower+1)/2; ++lCurPos)
    	{
    		lHighDigit = getTopNthDigit(x, lMaxPower, lCurPos);
    		lLowDigit = int((x/pow(10, double(lCurPos))))%10;
    		if(lHighDigit != lLowDigit || -1 == lHighDigit)
    			return false;
    	}
    	return true;
    }
};

int main()
{
	Solution* lSo = new Solution();
	int lInputNumber;
	while(true)
	{
		cin >> lInputNumber;
		if(-1 == lInputNumber)
			break;
		else
			cout << (lSo->isPalindrome(lInputNumber) ? "true":"false") << endl;
	}
	return 0;
}
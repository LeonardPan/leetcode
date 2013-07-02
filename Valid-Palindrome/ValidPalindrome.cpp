//valid palindrome
//Author: Leonard Pan

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long lLens = s.length();
        long lSteps = 0;
        string::iterator lLeftIter = s.begin();
        string::reverse_iterator lRightIter = s.rbegin();
        
        while(lSteps <= lLens-2)
        {
            char lLeftChar = 0;
            char lRightChar = 0;
            while( !(*lLeftIter >= 'a' && *lLeftIter <= 'z') 
                && !(*lLeftIter >= 'A' && *lLeftIter <= 'Z')
                && !(*lLeftIter >= '0' && *lLeftIter <= '9'))
                {
                    lLeftIter++;
                    lSteps++;
                    if (lLeftIter == s.end())
                        break;
                }
            while( !(*lRightIter >= 'a' && *lRightIter <= 'z') 
                && !(*lRightIter >= 'A' && *lRightIter <= 'Z')
                && !(*lRightIter >= '0' && *lRightIter <= '9'))
                {
                    lRightIter++;
                    lSteps++;
                    if (lRightIter == s.rend())
                        break;
                }
            //reach the end of string, finished
            if(lLeftIter == s.end() || lRightIter == s.rend())
                break;
                
            if(*lLeftIter >= 'A' && *lLeftIter <= 'Z')
                lLeftChar = *lLeftIter - ('A' - 'a');
            else
                lLeftChar = *lLeftIter;
                
            if(*lRightIter >= 'A' && *lRightIter <= 'Z')
                lRightChar = *lRightIter - ('A' - 'a');
            else
                lRightChar = *lRightIter;
                
            if(lLeftChar == lRightChar)
            {
                lLeftIter++;
                lRightIter++;
                lSteps += 2;
            }
            else
                break;
        }
        if(lSteps <= lLens-2)
            return false;
        else
            return true;
        }
};

int main()
{
	Solution* lSo = new Solution();
	string lInputStr;
	while(true)
	{
		getline(cin, lInputStr);
		if(0 == lInputStr.compare("exit"))
			break;
		else
			cout << (lSo->isPalindrome(lInputStr) ? "true":"false") << endl;
	}
}
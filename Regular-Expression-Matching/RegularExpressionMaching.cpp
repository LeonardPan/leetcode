//rugular expression maching
//Author: Leonard Pan
#include <string>
#include <iostream>

using namespace std;

class Solution{
public:
	bool isMatch(const char* s, const char* p){
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    		
		if('\0' == *s && '\0' == *p)
			return true;
		else if('\0' == *p)//only *s is a '\0' doesn't make a false, 'Cause maybe *p is a a*
			return false;

		//no *, simply compare 2 charactor
		if('*' != *(p+1)){
			if(*s == *p || ('.' == *p && '\0' != *s))
				return isMatch(s+1, p+1);
			else//mismatch
				return false;
		}
		//dealing with *
		else {
			int len = strlen(s);
			int i = 0, j = 0;
			while(1)
			{
				if(i > len)//already recursed all situations
					break;
				for(j = 0; j < i; ++j){
					if(*(s+j) != *p && ('.' != *p || '\0' == *s))//mismatch
						break;
				}
				//match
				if(i == j){
					if(isMatch(s+i, p+2))
						return true;
				}
				//dismatch
				++i;
			}
		}
		return false;
	}
};

int main()
{
    // Start typing your code here...
    Solution* pSo = new Solution();
    string s, p;
    while(cin >> s >> p)
    {
        if(0 == s.compare("exit"))
            break;
        cout << (pSo->isMatch(s.c_str(), p.c_str()) ? "true" : "false") << endl;
    }
}
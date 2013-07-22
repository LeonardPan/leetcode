//container with most water. O(nlog(n))
//Author: Leonard Pan

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	//the struct to store original indexes
    typedef struct indexedHeight{
            int height;
            int index;
            indexedHeight(int hi, int index){
                this->height = hi;
                this->index = index;
            }
    }indexHi;
	//the functor to compare and sort struct vector
    struct compareTheHeights{
        bool operator() (indexHi a, indexHi b) {
            return (a.height > b.height);
        }
    }compareHeight;

    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, leftMost, rightMost;
        long maxSize = 0, leftMaxSize = 0, rightMaxSize = 0;
        vector<indexHi> iHeight;
        for(i = 0; i < height.size(); ++i){
            iHeight.push_back(*(new indexHi(height[i], i)));
        }
        sort(iHeight.begin(), iHeight.end(), this->compareHeight);
        
		//maintain the left most and right most indexes in the left of current i
        leftMost = rightMost = iHeight[0].index;
        for(i = 1; i < iHeight.size(); ++i){
            if(iHeight[i].index > rightMost)
                rightMost = iHeight[i].index;
            else if(iHeight[i].index < leftMost)
                leftMost = iHeight[i].index;
			//all the heights on the left of i are higher than i, so, just use i as the height
            leftMaxSize = iHeight[i].height * (iHeight[i].index - leftMost);
            rightMaxSize = iHeight[i].height * (rightMost - iHeight[i].index);
            if ((leftMaxSize > rightMaxSize? leftMaxSize : rightMaxSize) > maxSize)
                maxSize = leftMaxSize > rightMaxSize? leftMaxSize : rightMaxSize;
        }
        return (int) maxSize;
    }
};

int main(){
	Solution *sol = new Solution();
	int i[4] = {3,2,1,3};
	vector<int> testVec(i, i+4) ;
	cout << sol->maxArea(testVec);
	return 0;
}
#include<set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = nums.size();
        if(count == 0) return 0;
        
        set<int> numSet;
        int left = 0;
        for(int right = 0; right < count; ++right) {
            int rightNum = nums[right];
            if (numSet.count(rightNum) == 0) {
                numSet.insert(rightNum);
                //left != right, we need to shrink the array
                if (left != right) {
                    nums[left++] = rightNum;
                }
                //left == right, the array should leave without change
                else {
                    ++left;
                }
            }
        }
        return left;
    }
};

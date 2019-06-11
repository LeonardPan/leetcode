class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retVec;
        int size = nums.size();
        for(int i = 0; i < size - 1; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if(nums[i] + nums[j] == target) {
                    retVec.push_back(i);
                    retVec.push_back(j);
                    return retVec;
                }
            }
        }
        return retVec;
    }
};

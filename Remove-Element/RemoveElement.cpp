class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        
        int left = 0, right = 0;
        while(right < size) {
            if (nums[right] != val) {
                nums[left++] = nums[right++];
            }
            else {
                ++right;
            }
        }
        return left;
    }
};

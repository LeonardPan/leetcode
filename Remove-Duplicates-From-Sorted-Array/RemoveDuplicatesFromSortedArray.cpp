class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, count = nums.size();
        if (count == 0) return 0;

        for (int right = 0; right < count; ++right) {
            if (nums[left] != nums[right]) {
                //left != right, we need to shrink the array
                if (left != right) {
                    nums[++left] = nums[right];
                }
                //left == right, the array should leave without change
                else {
                    ++left;
                }
            }
        }
        return left + 1;
    }
};

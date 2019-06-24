class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (right < 0) {
            return 0;
        }
        
        int mid = (left +  right) / 2;
        while(left < right - 1) {
            if (nums[mid] < target) {
                left = mid;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            //we got it
            else {
                return mid;
            }
            mid = (left + right) / 2;
        }
        //all right, now: left = right -1 or left == right
        //target location in the left of the left
        if (nums[left] > target) {
            if (left > 1) { return left -1;}
            else { return 0;}
        }
        //target is excact locat at the left
        else if(nums[left] == target) {
            return left;
        }
        //target is locate between left and right
        else if(nums[right] >= target) {
            return right;
        }
        //target is locate at the right of the right
        else {
            return right + 1;
        }
    }
};

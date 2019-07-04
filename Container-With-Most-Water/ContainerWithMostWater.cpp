class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned int maxArea = 0;
        unsigned int size = height.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                unsigned int shorter = height[i] < height[j] ? height[i] : height[j];
                unsigned int area = shorter * (j - i);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
};

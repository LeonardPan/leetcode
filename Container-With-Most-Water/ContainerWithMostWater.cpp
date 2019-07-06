class Solution {
public:
    struct bar {
        int _data;
        int _index;
        
        bar(int data, int index) : _data(data), _index(index) {}
    };
    struct compareBar {
        bool operator()(const bar& left, const bar& right) {
            return left._data > right._data;
        }
    };
    
    int maxArea(vector<int>& height) {
        //init
        vector<bar> barVec;
        int i = 0;
        for (int j = 0; j < height.size(); ++j) {
            barVec.push_back(bar(height[j], i++));
        }
        
        compareBar cmp;
        //sort by height
        sort(barVec.begin(), barVec.end(), cmp);
        // 8 8 7 6 5 4 3 2 1
        // 1 6 8 2 4 5 7 3 0
        
        unsigned int leftMostIndex = barVec[0]._index;
        unsigned int rightMostIndex = barVec[0]._index;
        unsigned int maxArea = 0;
        unsigned int size = height.size();
        for(i = 1; i < size; ++i) {
            //consider use the barVec[i] as the shorter bar to compose the conatiner, 
            //which means, we can use barVec[i] to calculate the area directly,
            //now only consider the bar on the left as the other bar,
            //we keep the left most and right most index, which is reuseable.
            if (barVec[i]._index < leftMostIndex) {
                leftMostIndex = barVec[i]._index;
            }
            else if (barVec[i]._index > rightMostIndex) {
                rightMostIndex = barVec[i]._index;
            }
            
            int leftArea = barVec[i]._data * (barVec[i]._index - leftMostIndex);
            int rightArea = barVec[i]._data * (rightMostIndex - barVec[i]._index);
            int largerArea = leftArea > rightArea ? leftArea : rightArea;
            if (largerArea > maxArea) {
                maxArea = largerArea;
            }
        }
        
        return maxArea;
    }
};

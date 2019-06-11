#include <algorithm>
class Solution {
    //define a node struct composited with index & data pair.
    class Node {
    public:
        int getIndex() const { return _index;}
        int getData() const { return _data;}
        Node(int index, int data) : _index(index), _data(data) {}
        
        //static bool compare(const Node& left, const Node& right) { return left.getData() < right.getData();}
    private:        
        int _index;
        int _data;
    };
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> retVec;
        std::vector<Node> nodeArr;
        int size = nums.size();
        //store the original index
        for(int i = 0; i < size; ++i) {
            nodeArr.emplace_back(i, nums[i]);
        }
        //std::sort(nodeArr.begin(), nodeArr.end(), Node::compare);
        std::sort(nodeArr.begin(), nodeArr.end(), [](const Node& left, const Node& right){
            return left.getData() < right.getData();
        });
        //similar to quick sort
        for(int left = 0, right = size - 1; left < right;)
        {
            if(nodeArr[left].getData() + nodeArr[right].getData() < target) {
                ++left;
            }
            else if (nodeArr[left].getData() + nodeArr[right].getData() > target) {
                --right;
            }
            else {
                retVec.push_back(nodeArr[left].getIndex());
                retVec.push_back(nodeArr[right].getIndex());
                return retVec;
            }
        }
        return retVec;
    }
};

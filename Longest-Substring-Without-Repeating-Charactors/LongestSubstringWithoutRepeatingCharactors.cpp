class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> q;
        int maxLength = 0;
        for (const auto& ch : s) {
            for (auto iter = q.begin(); iter != q.end(); ++iter) {
                //found duplicate
                if (*iter == ch) {
                    for (auto tmpIt = q.begin(); tmpIt != iter; ++tmpIt) {
                        q.pop_front();
                    }
                    //pop the element == ch
                    q.pop_front();
                    //there will only one match at most
                    break;
                }
            }
            //always push the ch
            q.push_back(ch);
            if (q.size() > maxLength) {
                maxLength = q.size();
            }
        }
        return maxLength;
    }
};

//cache the sayings from 1 to 30
vector<string> saying = { "1" };

class Solution {
public:
    string countAndSay(int n) {
        int counted = saying.size();
        //return the cached saying directly
        if (n <= counted) {
            return saying[n - 1];
        }

        //calculate the saying from the rightest to target
        for (int i = counted - 1; i < n - 1; ++i) {
            string tmp;
            char lastChar = saying[i][0];
            int count = 1;
            int size = saying[i].size();
            //say the current string from left to right
            for (int j = 1; j < size; ++j) {
                if (lastChar == saying[i][j]) {
                    ++count;
                }
                else {
                    tmp += ('0' + count);
                    tmp += lastChar;
                    lastChar = saying[i][j];
                    count = 1;
                }
            }
            tmp += ('0' + count);
            tmp += lastChar;
            //cache the current saying
            saying.push_back(tmp);
        }

        return saying[n - 1];
    }
};

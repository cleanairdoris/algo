#include <vector>
#include <string>
class Solution {
public:
    std::vector<std::vector<int>> largeGroupPositions(std::string s) {
        std::vector<std::vector<int>> ret;
        if (s.length() < 3)
            return ret;
        for (int i = 0; i < s.length(); ) {
            int j = 0;
            for (j = i + 1; j < s.length(); j++) {
                if(s[i] != s[j]) {
                    break;
                }
            }
            if (j - i >= 3) {
                std::vector<int> tmp(2,0);
                tmp[0] = i;
                tmp[1] = j-1;
                ret.push_back(tmp);
            }
            i = j;
        }
        return ret;
    }
};
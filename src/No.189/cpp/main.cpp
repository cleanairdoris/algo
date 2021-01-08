#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k == 0 || len== 0) return;
        k = k % len;
        revert(nums, 0, len - 1);
        revert(nums, 0, k-1);
        revert(nums, k, len - 1);
    }
    void revert(vector<int>& nums, int st, int end) {
        int tmp;
        while (st > end) {
            tmp = nums[st];
            nums[st] = nums[end];
            nums[end] = tmp;
            st++;
            end--;
        }

    }
};

int main()
{
    Solution aa;
    vector<int> src={1,2,3,4,5,6,7};
    int k = 3;
    aa.rotate(src, k);
    for (int i = 0; i< src.size(); i++)
        cout<<src[i]<< ",";
}
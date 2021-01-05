#include <vector>
class Solution {
public:
    //自底向上.leetcode提交耗时0ms
    int fib(int n) {
        if (n == 0) {  
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int pre1 = 0;
        int pre2 = 1;
        for (int i = 2; i <= n; i++)
        {
            int tmp = pre1;
            pre1 = pre2;
            pre2 += tmp;          
        }
        return pre2;
    }

    //递归解法，暴力解法，不用提交都知道耗时极大
    int fib1(int n) {
        if (n <= 0) {  
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        return fib1(n-1) + fib1(n-2);
    }

    //优化递归.leetcode提交耗时0ms
    int fib2(int n) {
        if (n <= 0) {  
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        std::vector<int> nums(n+1, 0);
        nums[1] = 1;
        nums[2] = 1;
        
        return fib_helper(nums, n);
    }
    int fib_helper(std::vector<int> & nums, int n) {
        if (nums[n] != 0) {
            return nums[n];
        }
        nums[n] = fib_helper(nums, n-1) + fib_helper(nums, n-1);
        return nums[n];
    }
};

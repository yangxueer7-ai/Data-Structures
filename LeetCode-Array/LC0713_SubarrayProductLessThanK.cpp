/*
 * LC0713. 乘积小于 K 的子数组（Subarray Product Less Than K）
 * 思路：可变长度滑动窗口
 * 1. 数组元素均为正整数；k <= 1 时不存在乘积小于 k 的非空子数组。
 * 2. 右指针加入元素并更新乘积；若乘积 >= k，就不断移动左指针缩小窗口。
 * 3. 窗口合法后，以 right 结尾的合法子数组共有 right - left + 1 个，累加到答案。
 * 复杂度：时间 O(n)，空间 O(1)。
 * 易错点：while 负责维护合法窗口；ans 的累加应放在 while 之后。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int left = 0;
        int mul = 1;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            mul *= nums[right];

            while (mul >= k) {
                mul /= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};

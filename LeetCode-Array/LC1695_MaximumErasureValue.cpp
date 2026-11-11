/*
 * LC1695. 删除子数组的最大得分 (Maximum Erasure Value)
 *
 * 算法：可变长度滑动窗口 + 哈希集合
 *
 * 思路：
 * 1. 窗口 [left, right] 中的元素必须互不相同，使用 unordered_set 记录元素。
 * 
 * 2. 右指针准备加入 nums[right] 时，如果集合中已有相同值，
 *    就不断移除左端元素：从 curSum 中减去、从集合中删除、left++。
 * 3. 直到 nums[right] 不再重复，将其加入集合和 curSum。
 * 
 * 4. 维护 maxSum = max(maxSum, curSum)，求合法窗口的最大元素和。
 *
 * 易错点：
 * - 一定要 st.insert(nums[right])，否则集合始终为空，无法检测重复。
 * 
 * - 收缩时必须同时更新 curSum 和 st，保持二者与窗口内容一致。
 * 
 * - 题目保证 nums[i] 为正整数，因此无需考虑负数导致的特殊最值情况。
 *
 * 时间复杂度：平均 O(n)，每个元素最多入窗、出窗各一次；哈希操作平均 O(1)。
 * 空间复杂度：O(n)，最坏情况下集合存储全部元素。
 */

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        int left = 0;
        int curSum = 0;
        int maxSum = 0;

        for (int right = 0; right < n; right++) {
            while (st.count(nums[right])) {
                curSum -= nums[left];
                st.erase(nums[left]);
                left++;
            }

            st.insert(nums[right]);
            curSum += nums[right];
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};

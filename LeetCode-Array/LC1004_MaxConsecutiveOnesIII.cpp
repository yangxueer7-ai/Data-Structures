/*
 * LeetCode 1004. 最大连续 1 的个数 III（Max Consecutive Ones III）
 *
 * 题型：可变长度滑动窗口
 * 核心思路：最多将 k 个 0 翻转为 1，等价于寻找「包含不超过 k 个 0」的最长连续子数组。
 *
 * 窗口定义：当前窗口为 [left, right]，zeroCount 记录窗口中 0 的数量。
 * 1. 右指针逐个扩展窗口；如果新加入的元素为 0，则 zeroCount++。
 * 2. 当 zeroCount > k 时，窗口不合法：不断右移 left。
 *    如果移出的元素为 0，需要同步将 zeroCount--。
 * 3. 窗口重新合法后，用 right - left + 1 更新最大长度。
 *
 * 时间复杂度：O(n)。左右指针都只会向右移动，每个元素最多进入和离开窗口各一次。
 * 空间复杂度：O(1)。只使用了固定数量的变量。
 *
 * 易错点：收缩窗口时，只有移出 0 才能减少 zeroCount；
 *         必须在窗口恢复合法之后更新最长长度。
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;       
        int zeroCount = 0;  // 窗口中 0 的个数，即需要翻转的次数
        int ans = 0;        

        for (int right = 0; right < n; right++) {
            // 扩展右端点：加入 0 就增加一次翻转需求
            if (nums[right] == 0) {
                zeroCount++;
            }

            // 窗口中 0 超过 k 个，必须收缩至重新合法
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

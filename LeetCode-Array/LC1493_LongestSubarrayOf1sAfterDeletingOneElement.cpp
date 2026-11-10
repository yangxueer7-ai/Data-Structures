/*
 * LC1493. 删掉一个元素以后全为 1 的最长子数组
 *
 * 思路：可变长度滑动窗口（与 LC1004 对照）
 * 1. 维护一个最多包含 1 个 0 的连续窗口，zeroCount 统计窗口内 0 的个数。
 * 2. 右指针加入元素；如果 zeroCount > 1，左指针持续右移，
 *    遇到被移出的 0 时，先将 zeroCount 减 1。
 * 3. 题目要求必须删除恰好一个元素：
 *    - 窗口里有 0，删除这个 0；
 *    - 窗口里没有 0，也必须删除一个 1。
 *    因此答案统一为窗口长度减 1，即 right - left。
 * 4. ans 初始化为 0；全为 0 或只有一个元素等情况自然返回 0。
 *
 * 易错点：收缩窗口时要同步更新 zeroCount；不要只在 zeroCount == 1 时更新答案。
 * 时间复杂度：O(n)，左右指针各最多移动 n 次。
 * 空间复杂度：O(1)。
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            ans = max(ans, right - left);
        }

        return ans;
    }
};


/*
 * ============================================================
 * LeetCode 209. 长度最小的子数组 (Minimum Size Subarray Sum)
 * 难度：Medium
 * 专题：Array / Sliding Window / Two Pointers
 *
 * 【核心思路】
 * 1. 维护一个连续窗口 [left, right]，以及窗口元素和 sum。
 * 2. 右指针不断扩张窗口：sum += nums[right]。
 * 3. 当 sum >= target 时，更新最短长度。
 * 4. 然后不断移动左指针，尝试缩小窗口。
 * 5. 如果不存在合法子数组，返回 0。
 *
 * 【滑动窗口模板】
 * 右指针扩张：sum += nums[right];
 *
 * while (sum >= target) {
 *     ans = min(ans, right - left + 1);
 *     sum -= nums[left];
 *     left++;
 * }
 *
 * 【为什么使用 while 而不是 if？】
 * 一个右端点可能对应多个满足条件的窗口。
 * 缩小一次后，窗口可能仍然满足 sum >= target。
 * 因此需要持续收缩，直到窗口不再合法，
 * 避免遗漏更短的子数组。
 *
 * 【易错点】
 * 1. sum += nums[right]，不能写成 sum = nums[left] + nums[right]。
 *    因为 sum 维护的是整个窗口的累计和，不只是两端元素。
 * 2. 更新 ans 必须在移除左端元素之前，保证窗口合法。
 * 3. 窗口长度 = right - left + 1，注意 +1。
 * 4. return 应放在 for 循环结束后，避免提前结束函数。
 * 5. ans 初始化为 INT_MAX，最终需要判断是否找到答案。
 * 6. 本题元素均为正整数，因此窗口可以单调扩张与收缩。
 *
 * 【复杂度】
 * 时间：O(n)，左右指针各最多移动 n 次。
 * 空间：O(1)，只使用常数个辅助变量。
 *
 * 右指针扩张，左指针收缩；
 * 满足条件先记录，再不断缩小寻找最优解。
 * ============================================================
 */
#include <vector>
#include <algorithm>

using namespace std;
class Solution209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            // 右指针扩张窗口，累计窗口和
            sum += nums[right];

            // 当前窗口满足要求，尝试不断缩小
            while (sum >= target) {
                // 先记录合法窗口的最短长度
                ans = min(ans, right - left + 1);

                // 移除左端元素，再移动左指针
                sum -= nums[left];
                left++;
            }
        }

        // 没有找到合法子数组则返回 0
        return ans == INT_MAX ? 0 : ans;
    }
};

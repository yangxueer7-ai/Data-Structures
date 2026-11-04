/*
 * LeetCode 1124. 表现良好的最长时间段 (Longest Well-Performing Interval)
 *
 * 思路：前缀和 + 哈希表（记录前缀和首次出现的位置）
 * 1. 每天工作时间 > 8 小时记为 +1，否则记为 -1。
 *    于是「劳累天数 > 不劳累天数」等价于「对应区间和 > 0」。
 * 
 * 2. sum 表示遍历到下标 i 时的前缀和；mp[s] 记录前缀和 s 第一次出现的下标。
 * 
 * 3. 若 sum > 0，则整个前缀 [0, i] 已经合法，长度为 i + 1。
 * 
 * 4. 若 sum <= 0，需要找到比 sum 小的历史前缀和 pre，使 sum - pre > 0。
 *    因为每次只增加 +1 或 -1：若历史上出现过更小的前缀和，
 *    一定先经过 sum - 1；最早的 sum - 1 不会比任何更小值出现得晚。
 *    因而只需查询最早的 mp[sum - 1]，用 i - mp[sum - 1] 更新最长长度。
 * 
 * 5. 同一前缀和只记录第一次出现的位置，不能覆盖，否则可能丢失最长区间。
 *
 * 易错点：历史位置是子数组起点的前一个下标，长度为 i - mp[sum - 1]，无需再 +1。
 * 这里 sum > 0 时单独处理从 0 开始的区间，所以不需要 mp[0] = -1。
 *
 * 时间复杂度：平均 O(n)，空间复杂度：O(n)。
 */

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < static_cast<int>(hours.size()); i++) {
            // 劳累的一天为 +1，不劳累的一天为 -1。
            sum += (hours[i] > 8 ? 1 : -1);

            if (!mp.count(sum)) {
                mp[sum] = i;
            }

            if (sum > 0) {
                // 整个 [0, i] 的区间和 > 0。
                ans = i + 1;
            }
            else if (mp.count(sum - 1)) {
                // 两个前缀和之差 > 0；下标相减得到区间长度。
                ans = max(ans, i - mp[sum - 1]);
            }
        }

        return ans;
    }
};

/*
 * LeetCode 0523 - 连续的子数组和 (Continuous Subarray Sum)
 *
 * 思路：前缀和取模 + 哈希表（保存余数最早出现的下标）
 * 1. 若两个前缀和对 k 取模的余数相同，则它们的差（中间子数组的和）是 k 的倍数。
 * 
 * 2. mp[remainder] 保存这个余数第一次出现的下标。取最早的下标，才能得到最长的候选区间。
 * 
 * 3. mp[0] = -1 表示空前缀（下标 -1）的余数为 0，用于处理从下标 0 开始的子数组。
 * 
 * 4. LC0523 规定子数组至少含两个元素，因此需满足 i - mp[remainder] >= 2。
 *
 * 易错点：
 * - 长度 = 当前下标 i - 历史前缀和下标，顺序不能写反，也不需要额外 +1。
 * - 余数已出现时不要覆盖最早下标。
 * - 本题 k >= 1；使用 long long 保存前缀和，避免累加溢出。
 *
 * 时间复杂度：平均 O(n)；空间复杂度：O(min(n, k))。
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;  // 空前缀：余数 0 最早出现在下标 -1

        long long sum = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            sum += nums[i];
            int remainder = static_cast<int>(sum % k);

            if (!mp.count(remainder)) {
                // 首次出现该余数，记录最早下标
                mp[remainder] = i;
            }
            else if (i - mp[remainder] >= 2) {
                // 两次同余的前缀和之差是 k 的倍数，且长度至少为 2
                return true;
            }
        }

        return false;
    }
};

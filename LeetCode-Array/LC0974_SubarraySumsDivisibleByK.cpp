/*
 * LeetCode 0974. 和可被 K 整除的子数组 (Subarray Sums Divisible by K)
 *
 * 题型：前缀和 + 同余 + 哈希表计数
 * 核心：如果两个前缀和对 k 取模的余数相同，则这两个前缀之间的
 *       连续子数组之和一定能被 k 整除。
 *
 * 哈希表：mp[remainder] 表示此前「前缀和余数为 remainder」的出现次数。
 * 1. mp[0] = 1：空前缀（还没取任何元素）的余数是 0，出现过一次。
 * 2. 遍历时先更新前缀和，再计算规范化的余数 remainder。
 * 3. ans += mp[remainder]：每个历史相同余数都对应一个合法子数组。
 * 4. mp[remainder]++：将当前前缀和留给后面的右端点使用。
 *
 * 易错点：
 * - 必须「先统计，再更新」，否则当前前缀和与自身配对，会多算空子数组。
 * - C++ 的负数取模可能得到负余数，需用 ((sum % k) + k) % k 归一化。
 * - 本题求数量，哈希表保存出现次数；LC0523 判断长度，保存最早下标。
 *
 * 时间复杂度：平均 O(n)；空间复杂度：O(min(n, k))（k 为正整数）。
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // 余数 -> 历史出现次数
        mp[0] = 1;                    // 空前缀的余数为 0

        long long sum = 0;            
        int ans = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            sum += nums[i];
            int remainder = static_cast<int>(((sum % k) + k) % k);

            // 先统计：历史上相同余数出现多少次，就新增多少个合法子数组
            ans += mp[remainder];

            // 再更新：将当前前缀和记录到哈希表，不能提前更新
            mp[remainder]++;
        }

        return ans;
    }
};

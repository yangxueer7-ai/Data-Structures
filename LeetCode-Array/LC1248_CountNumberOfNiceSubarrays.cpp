/*
 * LeetCode 1248. 统计「优美子数组」(Count Number of Nice Subarrays)
 *
 * 思路：奇偶映射 + 前缀和 + 哈希表频次统计
 * 1. 将奇数映射为 1、偶数映射为 0，子数组中恰好有 k 个奇数
 *    等价于映射后该子数组的元素和恰好为 k。
 * 2. 设当前前缀和为 sum，若历史前缀和 pre = sum - k，
 *    则二者之间的连续子数组恰好包含 k 个奇数。
 * 3. mp[pre] 记录此前前缀和 pre 出现的次数；每一个历史位置
 *    都能构成一个合法子数组，因此 ans += mp[sum - k]。
 * 4. 必须先查询再更新 mp[sum]，否则会把当前前缀和与自身配对。
 *
 * 初始化：mp[0] = 1，表示遍历开始前存在一个和为 0 的空前缀，
 *         用于统计从下标 0 开始的合法子数组。
 *
 * 时间复杂度：平均 O(n)；空间复杂度：O(n)。
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // key：奇数个数的前缀和；value：此前出现的次数
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            // 奇数贡献 1，偶数贡献 0
            sum += (nums[i] % 2 == 0 ? 0 : 1);

            // 区间和 = 当前前缀和 - 历史前缀和 = k
            // 没有出现过 sum-k 时，mp[sum-k] 自动初始化为 0
            ans += mp[sum - k];
            mp[sum]++;
        }

        return ans;
    }
};

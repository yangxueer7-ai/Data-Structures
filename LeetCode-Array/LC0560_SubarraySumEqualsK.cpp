/*
 * LeetCode 560. 和为 K 的子数组 (Subarray Sum Equals K)
 * 难度：Medium
 * 算法：前缀和 /  nordered_map
 *
 * 【题意】
 * 给定整数数组 nums 和整数 k，统计所有和恰好等于 k 的
 * 连续非空子数组的数量。数组中允许出现正数、负数和 0。
 *
 * 【方法一：暴力枚举】
 * 固定左端点 i，向右枚举终点 j，不断累加区间和。
 * 如果 sum == k，则 ans++。
 * 时间复杂度：O(n^2)，空间复杂度：O(1)。
 *
 * 【方法二：前缀和 + 哈希表】
 * 设 sum 为当前前缀和，pre 为之前某个位置的前缀和。
 *
 * 由 sum - pre = k，可得：
 * pre = sum - k
 * 因此，只需查询此前有多少个前缀和等于 sum-k，
 * 就能知道有多少个以当前位置结尾的合法子数组。
 *
 * 【哈希表定义】
 * unordered_map<int, int> cnt;
 *
 * key   ：历史前缀和
 * value ：该前缀和出现的次数
 *
 * cnt[sum-k]：此前满足条件的前缀和出现次数。
 * cnt[sum]++：记录当前前缀和，供后续使用。
 *
 * 【核心过程】
 * 1. 初始化 sum=0，ans=0。
 * 2. cnt[0]=1，表示空前缀的和为 0，出现过一次。
 * 3. 遍历数组：
 *    - sum += nums[i]，更新当前前缀和。
 *    - ans += cnt[sum-k]，统计新的合法子数组。
 *    - cnt[sum]++，记录当前前缀和。
 * 4. 返回 ans。
 *
 * 【易错点】
 * 1. cnt[0]=1 不能遗漏，否则会漏掉从下标 0 开始的子数组。
 * 2. cnt 存储的是前缀和出现次数，而不是数组元素出现次数。
 * 3. 哈希表记录的是 sum，不是每轮直接记录 sum-k。
 * 4. 必须先查询 cnt[sum-k]，再执行 cnt[sum]++。
 *    否则 k=0 时可能把空子数组统计进去。
 * 5. ans += cnt[sum-k]，不能简单写 ans++。
 *    因为相同前缀和可能出现多次。
 * 6. unordered_map 的 [] 访问不存在的整数键时，
 *    会自动插入该键，并将对应的 int 初始化为 0。
 * 7. 本题允许负数，不能直接使用 LC209 的滑动窗口模板。
 *
 * 【复杂度】
 * 时间复杂度：平均 O(n)，哈希表查询与更新平均 O(1)。
 * 空间复杂度：O(n)，最坏情况下记录 O(n) 个不同前缀和。
 *
 * 前缀和求差值，哈希表存历史次数；
 * 先查询 sum-k，再记录当前 sum。
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution560 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int ans = 0;

        unordered_map<int, int> cnt;
        cnt[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += cnt[sum - k];
            cnt[sum]++;
        }

        return ans;
    }
};
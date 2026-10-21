/*
 * LeetCode 454. 4Sum II（四数相加 II）
 *
 * 算法：哈希表 + 两数之和计数
 *
 * 核心思路：
 * 1. 将四个数组拆分为两组：(nums1, nums2)、(nums3, nums4)
 * 2. 使用 unordered_map 统计第一组所有 a+b 的出现次数
 * 3. 枚举第二组的 c+d，寻找 target = -(c+d)
 * 4. ans += mp[target]，累加所有满足条件的四元组数量
 *
 * 易错点：
 * 1. 哈希表的 value 是出现次数，而不是下标
 * 2. 需要 ans += mp[target]，不能简单 ans++
 * 比如 mp[target] = 3 说明有三种a+b的组合可以与当前的c+d配对，如果当前有两组c+d满足mp[target] = 3
 * 那么得到的一组ans数量就是 3 * 2 = 6
 * 3. 不同下标组成的四元组需要分别统计
 *
 * 时间复杂度：O(n^2)，平均情况
 * 空间复杂度：O(n^2)
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution454 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp; //key是加和，value是次数
        int ans = 0;

        // nums1和nums2的 a+b和值
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        // nums3+nums4 = c+d 
        for (int c : nums3) {
            for (int d : nums4) {
                // target就是对应的a+b的值 
                // 即a + b = -(c+d)
                // mp[target]所记录的累加进ans
                int target = -(c + d);
                if (mp.count(target)) {
                    ans += mp[target];
                }
            }
        }

        return ans;

    }
};


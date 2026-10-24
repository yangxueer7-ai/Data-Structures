/*
 * LeetCode 350. Intersection of Two Arrays II
 * 两个数组的交集 II
 *
 * 算法：哈希表 / unordered_map / 频次统计
 *
 * 核心思路：
 * 1. 使用 unordered_map<int,int> 统计 nums1 中各元素的出现次数。
 * 2. 遍历 nums2，检查当前元素在哈希表中的剩余次数。
 * 3. 如果 mp[x] > 0，说明该元素属于交集。
 * 4. 将 x 加入答案，并执行 mp[x]--，消耗一次出现次数。
 * 5. 返回最终交集数组。
 *
 * 哈希表定义：
 * key   -> 数字 x
 * value -> 数字 x 剩余可匹配的次数
 *
 * 时间复杂度：平均 O(n + m)
 * 空间复杂度：O(n)，包含哈希表和结果数组
 *
 * 易错点：
 * 1. LC349 要去重，LC350 要保留重复元素。
 * 2. 找到交集元素后必须 mp[x]--。
 * 3. mp[x] 在键不存在时会自动插入默认值 0。
 * 4. 返回数组中每个数字出现次数不能超过两个数组
 *    中该数字出现次数的较小值。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution350 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int x : nums1) {
            mp[x]++;
        }

        for (int x : nums2) {
            if (mp[x] > 0) {
                ans.push_back(x);
                mp[x]--;
            }
        }

        return ans;
    }
};
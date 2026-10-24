/*
 * LeetCode 219. Contains Duplicate II
 * 存在重复元素 II
 *
 * 算法：哈希表 / unordered_map / 下标映射
 *
 * 核心思路：
 * 1. 使用 unordered_map<int, int> 记录元素最近一次出现的下标。
 * 2. 遍历 nums，判断当前元素是否已经出现过。
 * 3. 若出现过，计算当前下标与最近一次出现下标的距离。
 * 4. 若距离 <= k，说明存在满足条件的两个不同下标，
 *    直接返回 true。
 * 5. 否则更新该元素最近一次出现的下标。
 * 6. 遍历结束仍未找到，返回 false。
 *
 * 哈希表定义：
 * key   -> 数组中的元素 nums[i]
 * value -> 该元素最近一次出现的下标
 *
 * STL 知识点：
 * - mp.count(x)：判断键 x 是否存在，结果为 0 或 1
 * - mp[x] = i：插入或更新键对应的下标
 *
 * 时间复杂度：平均 O(n)
 * 空间复杂度：O(n)
 *
 * 易错点：
 * 1. mp.count(x) 返回出现次数（0 或 1），不是下标。
 * 2. 计算距离必须使用 i - mp[x]。
 * 3. 必须先检查距离，再更新 mp[x] = i。
 * 4. 只需保存最近一次出现的下标。
 * 5. 从左向右遍历，i >= mp[x]，不需要 abs()。
 * 6. 题目要求两个不同下标，不能与自身比较。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            //key--nums中的元素 value--最近一次出现的下标，每次遍历到更新
            int x = nums[i];

            if (mp.count(x)) {
                int len = i - mp[x];

                if (len <= k) {
                    return true;
                }
            }

            mp[x] = i;
        }

        return false;

    }
};
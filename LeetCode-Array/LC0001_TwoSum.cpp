/*
 * LeetCode 1. 两数之和 (Two Sum)
 * 难度：Easy
 * 算法：unordered_map
 *
 * 【题意】
 * 给定整数数组 nums 和目标值 target，
 * 找到两个不同下标的元素，使它们的和等于 target，
 * 返回这两个元素的下标。
 *
 * 【核心思路】
 * 使用哈希表记录已经遍历过的数字及其下标。
 * 对于当前元素 nums[i]，计算需要寻找的补数：
 * need = target - nums[i]
 *
 * 如果 need 已经出现，则直接返回对应的两个下标；
 * 否则记录当前元素，继续向后遍历。
 *
 * 【哈希表定义】
 * unordered_map<int, int> mp;
 *
 * key   ：已经遍历过的数字 nums[i]
 * value ：该数字对应的下标 i
 *
 * 【算法过程】
 * 1. 创建空哈希表 mp。
 * 2. 从左往右遍历数组：
 *    - 计算 need = target - nums[i]。
 *    - 使用 mp.find(need) 判断补数是否存在。
 *    - 如果存在，返回 {mp[need], i}。
 *    - 否则执行 mp[nums[i]] = i，记录当前数字。
 * 3. 如果没有找到，返回空数组 {}。
 *
 * 【易错点】
 * 1. mp[nums[i]] = i：键是数字，值是下标。
 * 2. 返回 {mp[need], i}，不能写成 {mp[need], mp[i]}。
 * 3. 必须先查询，再插入，避免同一个元素被使用两次。
 * 4. mp.find(need) != mp.end() 表示补数已经存在。
 * 5. mp[key] 访问不存在的键时会自动插入默认值，
 *    因此只判断是否存在时，优先使用 find()。
 *
 * 【与 LC560 的区别】
 * LC1  ：key=数组元素，value=元素下标。
 *        查询 target-nums[i]，返回两个下标。
 *
 * LC560：key=历史前缀和，value=出现次数。
 *        查询 sum-k，累加合法子数组数量。
 *
 * 【复杂度】
 * 时间复杂度：平均 O(n)，哈希表查询和插入平均 O(1)。
 * 空间复杂度：O(n)，最多记录 n 个数字。
 
 */

#include <vector>
#include <unordered_map>

using namespace std;


class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return { mp[need],i };
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

/*
 * LeetCode 128. 最长连续序列 (Longest Consecutive Sequence)
 * 专题：哈希表 / unordered_set
 *
 * 【题意】
 * 给定无序整数数组 nums，返回最长的数值连续序列的长度。
 * 例如 nums = {100, 4, 200, 1, 3, 2}，答案为 4（1, 2, 3, 4）。
 * 不要求连续元素在原数组中相邻，且要达到平均 O(n) 时间复杂度。
 *
 * 【核心思路】
 * 1. 将 nums 插入 unordered_set，去重并支持平均 O(1) 的存在性查询。
 * 2. 对每个 x，只有在 x-1 不存在时，才从 x 启动连续序列扫描。
 *    若 x-1 存在，则 x 不是序列起点，跳过以避免重复扫描。
 * 3. 从起点向后检查 current+1，找到就使 current 和 len 都加 1。
 * 4. 每段扫描结束后，用 ans = max(ans, len) 更新全局最长长度。
 *
 * 【易错点】
 * - unordered_set<int> 只保存元素，不记录次数；插入用 insert(x)，
 *   而非 unordered_map 的 mp[x]++。
 * 
 * - 判断是否为起点应看 x-1 是否存在，不是看 x+1。
 * 如果x-1不存在说明x是起点，从x开始向后扩展
 * 如果x-1存在，说明x不为起点，跳过x，避免重复扫描
 * 
 * 
 * - len 初始化为 1：起点本身也占一个长度；长度更新放在 while 外。
 * - nums 为空时答案为 0
 *
 * 【复杂度】
 * 设 n = nums.size()。
 * - 平均时间复杂度：O(n)。集合构造及查找平均 O(1)；每一段序列
 *   只从起点扩展一次，所有 while 的总步数不超过不同元素数。
 * - 空间复杂度：O(n)，哈希集合存储去重后的元素。
 * 注：unordered_set 极端哈希冲突情况下不保证最坏 O(n) 时间。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        int ans = 0;
        for (int x : st) {
            // 只有当x-1 即x的前驱不存在时，x 才是连续序列的起点。
            if (!st.count(x - 1)) {
                int current = x;
                int len = 1;

                // 检查x的后继是否存在，若存在继续拓展序列
                // 只有是起点的x才会开始从头扩展，从而达到时间复杂度为O(N)的要求
                while (st.count(current + 1)) {
                    current++;
                    len++;
                }

                ans = max(ans, len);
            }
        }
        return ans;
    }
};

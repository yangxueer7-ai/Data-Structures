/*
 * LeetCode 242. 有效的字母异位词 (Valid Anagram)
 * 难度：Easy
 * 算法：哈希计数思想 / 字符频次数组
 *
 * 【题意】
 * 给定两个字符串 s 和 t，判断它们是否为字母异位词。
 * 字母异位词要求每种字符的出现次数完全相同，
 * 但不要求字符顺序相同。
 *
 * 【核心思路】
 * 使用长度为 26 的频次数组 cnt 记录字符出现次数。
 * 遍历 s 时，对应字符计数 +1；
 * 遍历 t 时，对应字符计数 -1。
 * 如果最终所有位置均为 0，则两字符串是字母异位词。
 *
 * 【算法过程】
 * 1. 如果 s.size() != t.size()，直接返回 false。
 * 2. 创建 vector<int> cnt(26, 0)。
 * 3. 遍历 s，执行 cnt[c-'a']++。
 * 4. 遍历 t，执行 cnt[c-'a']--。
 * 5. 遍历 cnt，若存在非零元素则返回 false。
 * 6. 所有频次均为 0，返回 true。
 *
 * 【STL / C++ 语法】
 * ④ cnt[c - 'a']++ / cnt[c - 'a']--
 *    分别将对应位置的整数增加 1 / 减少 1。
 *    并不是哈希表自动统计，而是我们主动维护计数。
 *
 * 【易错点】
 * 1. 字符串长度相同，不代表一定是字母异位词。
 * 2. 必须检查全部 26 个频次是否都为 0。
 * 3. cnt[c-'a'] 才是正确下标，不能直接使用 cnt[c]。
 * 4. 字母异位词不要求顺序相同，不需要比较 s == t。
 *
 * 【与其他题目的联系】
 * LC49 ：排序字符串作为 key，使用 unordered_map 分组。
 * LC438：定长滑动窗口 + 字符频次，寻找异位词起点。
 * LC567：定长滑动窗口 + 字符频次，判断排列是否存在。
 * LC242：直接对两个字符串的频次进行加减抵消。
 *
 * 【复杂度】
 * 时间复杂度：O(n)，其中 n 为字符串长度。
 * 空间复杂度：O(1)，只使用固定大小的 26 位计数数组。
 *
 * s 中字符频次加一，t 中字符频次减一，
 * 最终全部归零，即为字母异位词。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution242 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (char c : t) {
            cnt[c - 'a']--;
        }

        for (int x : cnt) {
            if (x != 0) {
                return false;
            }
        }

        return true;
    }
};
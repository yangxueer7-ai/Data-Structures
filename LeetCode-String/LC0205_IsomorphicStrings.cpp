/*
 * LeetCode 205. Isomorphic Strings
 * 同构字符串
 *
 * 算法：unordered_map / 双向映射
 *
 * 核心思路：
 * 1. 两个字符串同构，要求字符之间建立一一映射关系。
 * 2. 使用两个哈希表分别记录：
 *    mp1：s -> t
 *    mp2：t -> s
 * 3. 遍历相同下标的两个字符 a、b。
 * 4. 若 a 已经映射到其他字符，返回 false。
 * 5. 若 b 已经被其他字符映射，返回 false。
 * 6. 没有冲突时，建立双向映射。
 *
 * 状态判断：
 * mp1.count(a) && mp1[a] != b
 *     检查是否出现一对多。
 *
 * mp2.count(b) && mp2[b] != a
 *     检查是否出现多对一。
 *
 * STL 知识点：
 * - unordered_map<char, char>：字符映射哈希表
 * - count(key)：判断键是否存在
 * - mp[key]：访问或修改键对应的值
 *
 * 时间复杂度：平均 O(n)
 * 空间复杂度：O(1)，字符集大小固定
 *
 * 易错点：
 * 1. 必须同时检查一对多和多对一。
 * 2. 相同下标决定当前字符对应关系。
 * 3. 相同字符在不同位置必须保持映射一致。
 * 4. mp[key] 在键不存在时会自动插入默认值。
 * 5. 正向记录使用 mp1[a] = b。
 * 6. 反向记录使用 mp2[b] = a。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution205 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1; // s->t
        unordered_map<char, char> mp2; // t->s

        for (int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];

            // a以前出现过 且映射的字符不是b 说明一对多了！
            if (mp1.count(a) && mp1[a] != b) {
                return false;
            }

            if (mp2.count(b) && mp2[b] != a) {
                return false;
            }

            // 建立映射关系
            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};
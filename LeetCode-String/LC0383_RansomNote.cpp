/*
 * LeetCode 383. Ransom Note（赎金信）
 *
 * 算法：哈希思想 + 字符频次数组
 *
 * 核心思路：
 * 1. 使用长度为 26 的数组统计 magazine 的字符频次。
 * 2. 遍历 ransomNote，每使用一个字符，频次减 1。
 * 3. 如果某个字符的剩余频次小于 0，说明字符不足，
 *    立即返回 false。
 * 4. 如果所有字符都能够满足，返回 true。
 *
 * 易错点：
 * 1. 字符映射下标：cnt[c - 'a']。
 * 2. 可以先减再判断 < 0，也可以先判断 == 0 再减。
 * 3. magazine 允许存在多余字符，不需要最终全部归零。
 * 4. 本题只涉及小写字母，使用频次数组比哈希表更简单。
 *
 * 时间复杂度：O(m + n)
 * 空间复杂度：O(1)
 * 我这里使用了两种做法 频次/哈希 这题频次数组更快，但是哈希表更通用一点~
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);

        for (char x : magazine) {
            cnt[x - 'a']++;
        }

        for (char y : ransomNote) {
            cnt[y - 'a']--;
            if (cnt[y - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution_Hash {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char c : magazine) {
            mp[c]++;
        }

        for (char c : ransomNote) {
            auto it = mp.find(c);
            // 如果字符c压根没出现在magazine，或者字符c剩余数量为0，不够用，返回false
            if (mp.find(c) == mp.end() || it->second == 0) {
                return false;
            }

            it->second--;
        }

        return true;
    }
};
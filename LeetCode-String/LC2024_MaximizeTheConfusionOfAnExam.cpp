/*
 * LeetCode 2024. 考试的最大困扰度
 * 难度：Medium
 * 算法：可变长度滑动窗口 + 双目标枚举
 *
 * 【核心思路】
 * 给定仅包含 'T' 和 'F' 的字符串，最多修改 k 个字符，
 * 求修改后最长连续相同字符的长度。
 *
 * 分别考虑两种情况：
 * 1. 将窗口内的字符全部变成 'T'
 * 2. 将窗口内的字符全部变成 'F'
 *
 * 对两种情况分别使用滑动窗口，取最大值。
 *
 * 【窗口维护】
 * target：希望窗口最终变成的字符。
 * count：窗口中与 target 不同、需要修改的字符数量。
 *
 * 窗口合法条件：count <= k
 *
 * 1. right 右移，加入新字符。
 * 2. 如果 s[right] != target，count++。
 * 3. 当 count > k 时，不断移动 left 收缩窗口。
 * 4. 窗口合法后更新最长长度。
 *
 * 【易错点】
 * 1. 题目要求最多修改 k 次，而不是恰好 k 次。
 *    因此不能只在 count == k 时更新答案。
 *
 * 2. while(count > k) 结束后窗口必然合法，
 *    可以直接更新 maxLen。
 *
 * 3. 收缩窗口时，只有移除的字符与 target 不同，
 *    才需要执行 count--。
 *
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(
            getMaxLen(answerKey, k, 'T'),
            getMaxLen(answerKey, k, 'F')
        );
    }

    int getMaxLen(const string& s, int k, char target) {
        int left = 0;
        int count = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // 加入新字符，统计需要修改的数量
            if (s[right] != target) {
                count++;
            }

            // 修改次数超出限制，收缩窗口
            while (count > k) {
                if (s[left] != target) {
                    count--;
                }
                left++;
            }

            // 此时窗口合法，更新最大长度
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

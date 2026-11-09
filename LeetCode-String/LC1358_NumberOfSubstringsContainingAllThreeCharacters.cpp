/*
 * LC1358. 包含所有三种字符的子字符串数目
 *
 * 思路：可变长度滑动窗口 + 计数
 * 1. 字符串仅包含 a、b、c，用 cnt[3] 维护当前窗口中三种字符的频次。
 * 
 * 2. 每次扩展右端点后，只要三种字符均出现，就不断右移左端点，
 *    直到窗口首次变为不合法（至少缺少一种字符）。
 * 
 * 3. 此时以 right 结尾的合法子串起点恰好是 [0, left-1]，
 *    因而本轮新增 left 个合法子串，执行 ans += left。
 *
 * 易错点：
 * - 本题“合法时收缩”，不同于“非法时收缩”的常见窗口模板。
 * - 统计公式是 ans += left，而不是 ans += right - left + 1。
 * - 计数包含 a、b、c 各至少一个，允许同一种字符重复出现。
 *
 * 时间复杂度：O(n)，左右指针各最多遍历一遍。
 * 空间复杂度：O(1)，计数数组长度固定为 3。
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            cnt[s[right] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                cnt[s[left] - 'a']--;
                left++;
            }

            ans += left;
        }

        return ans;
    }
};

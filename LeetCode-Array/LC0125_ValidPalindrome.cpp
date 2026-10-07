/*
 * LeetCode 125. Valid Palindrome
 * 题目：验证回文串
 *
 * 核心思路：
 * 左右双指针。
 *
 * left：
 * 从字符串左边开始向右移动。
 * right：
 * 从字符串右边开始向左移动。
 *
 * 因为题目要求：
 * - 忽略非字母数字字符
 * - 忽略大小写
 *
 * 所以每一轮需要先做两件事：
 * 1. 左边如果不是字母或数字：
 *    left++
 * 2. 右边如果不是字母或数字：
 *    right--
 *
 * 然后比较：
 * tolower(s[left]) 和 tolower(s[right])
 *
 * 如果不同：
 *     return false;
 *
 * 如果相同：
 *     left++;
 *     right--;
 * 当 left >= right 时，
 * 说明所有有效字符都匹配成功，
 * 返回 true。
 *
 * 常用函数：
 *
 * isalnum(c)
 * 判断字符 c 是否为字母或数字。
 *
 * tolower(c)
 * 把字符 c 转成小写。
 *
 * 易错点：
 * 1. 遇到无效字符不能直接 continue，
 *    必须先移动对应指针，否则会死循环。
 *
 * 2. 最后循环正常结束时应该 return true。
 *
 * 3. 内层跳过字符时也要保证 left < right，
 *    防止指针越界或交叉后继续访问。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <cctype>
#include <string>
using namespace std;

class Solution125 {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        if (n == 0) {
            return true;
        }

        int left = 0;
        int right = n - 1;

        while (left < right) {
            // 左边不是字母或数字，左指针右移
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // 右边不是字母或数字，右指针左移
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // 忽略大小写比较
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
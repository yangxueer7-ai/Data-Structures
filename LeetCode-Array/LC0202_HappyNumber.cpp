/*
 * LeetCode 202. Happy Number（快乐数）
 *
 * 算法：哈希集合 + 模拟 
 *
 * 核心思路：
 * 1. 不断计算整数各位数字的平方和，更新 n。
 * 2. 使用 unordered_set 记录计算过程中出现过的数字。
 * 3. 如果 n == 1，说明成功到达 1，返回 true。
 * 4. 如果 n 已经出现过，说明进入循环，返回 false。进入循环就不可能到达1，不可能是快乐数。
 *
 * 易错点：
 * 1. n % 10：提取个位数字。
 * 2. n /= 10：删除个位
 * 3. seen.count(n)：
 *    - 返回 0：数字尚未出现。
 *    - 返回 1：数字已经出现。
 * 4. 出现重复数字时必须 return false，
 *    否则 n 无法更新，会陷入死循环
 * 5. unordered_set 只保存不同的元素，不存储出现次数。
 *
 * 复杂度：
 * 时间：每次 getNext 为 O(log n)，哈希操作平均 O(1)。
 *       对于题目限定的 32 位整数，整个过程为 O(log n)。
 * 空间：O(1)，32 位整数范围内可出现的状态数量有固定上界。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution202 {
public:
    bool isHappy(int n) {
        // 记录计算过程中已经出现过的数字
        unordered_set<int> seen;

        while (n != 1) {

            // 当前数字未出现过
            if (seen.count(n) == 0) {
                seen.insert(n);   
                n = getNext(n);   // 计算各位平方和
            }
            else {
                // 数字重复出现，说明进入循环
                return false;
            }
        }

        return true;
    }

    // 计算整数各位数字的平方和
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;    // 提取个位
            sum += digit * digit; 
            n /= 10;               // 删除个位
        }

        return sum;
    }
};
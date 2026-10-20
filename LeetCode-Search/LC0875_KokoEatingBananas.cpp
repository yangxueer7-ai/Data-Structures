/*
 * LeetCode 875. Koko Eating Bananas
 * 爱吃香蕉的珂珂
 *
 * 算法：二分查找 / 最小可行值
 *
 * 核心思路：
 * 1. 二分的对象不是数组下标，而是吃香蕉的速度 k。
 * 2. 速度越大，所需时间越短，满足单调性。
 * 3. 在 [1, max(piles)] 内寻找最小可行速度。
 * 4. 对于速度 mid，计算吃完所有香蕉所需的小时数。
 * 5. 若 hours > h，说明速度太慢，增大速度。
 * 6. 若 hours <= h，说明当前速度可行，尝试更小的速度。
 *
 * 时间计算：
 * hours += (p + (long long)mid - 1) / mid;
 * 使用整数运算实现向上取整。
 *
 * 二分边界：
 * - hours > h  : left = mid + 1
 * - hours <= h : right = mid
 *
 * 终止条件：
 * while (left < right)
 * 循环结束时 left == right，即最小可行速度。
 *
 * 时间复杂度：O(n * log M)
 * 空间复杂度：O(1)
 * n 为香蕉堆数，M 为最大香蕉堆的数量。
 *
 * 易错点：
 * 1. mid 代表当前测试的速度，而不是数组下标。
 * 2. 计算小时数必须向上取整。
     【p/k的向上取整： (p+k-1) / k 】
 * 3. 使用 long long 防止整数溢出。
 * 4. 当前速度可行时，必须保留 mid。
 * 5. while(left < right) 配合 right = mid。
 * 6. 最终返回 left 或 right 均可。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution875 {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours += (p + (long long)mid - 1) / mid;
            }

            if (hours > h) {
                //慢了，增加速度
                left = mid + 1;
            }
            else {
                //当前速度可行，找更小的
                right = mid;
            }
        }

        return right;
    }
};
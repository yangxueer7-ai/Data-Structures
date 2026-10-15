/*
 * LeetCode 162. 寻找峰值 (Find Peak Element)
 * 难度：Medium
 * 算法：二分查找 / 趋势判断
 *
 * 【题意】
 * 找到任意一个严格大于相邻元素的峰值，返回其下标。
 * 数组两端之外视为负无穷，相邻元素互不相等。
 *
 * 【核心思路】
 * 利用 nums[mid] 与 nums[mid+1] 的大小关系判断趋势。
 * 每次缩小搜索区间，并保证区间中至少存在一个峰值。
 *
 * 【二分过程】
 * 1. 使用 [left, right]，循环条件 left < right。
 * 2. nums[mid] < nums[mid+1]：处于上坡，
 *    右侧一定存在峰值，left = mid + 1。
 * 3. 否则处于下坡，左侧（包含 mid）一定存在峰值，
 *    right = mid。
 * 4. left == right 时，返回该下标。
 *
 * 【易错点】
 * 1. right = mid，不能写成 mid - 1，因为 mid 可能是峰值。
 * 2. left < right 保证 mid < right，访问 mid+1 不会越界。
 *
 * 【复杂度】
 * 时间：O(log n)
 * 空间：O(1)

 * 上坡向右找，下坡保留 mid，始终维护存在峰值的区间。
 */

#include <vector>

using namespace std;

class Solution162 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return right;
    }
};
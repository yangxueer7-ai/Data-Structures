/*
 * LeetCode 74. 搜索二维矩阵 (Search a 2D Matrix)
 * 难度：Medium
 * 算法：二分查找 / 二维数组
 *
 * 【题意】
 * 给定一个 m × n 的矩阵，每行从左到右递增，
 * 且下一行的第一个元素大于上一行的最后一个元素。
 * 判断 target 是否存在于矩阵中。
 *
 * 【核心思路】
 * 将二维矩阵逻辑上视为一个长度为 m*n 的有序一维数组，
 * 不需要真正展开，直接利用下标映射访问元素。
 *
 * 【下标映射】
 * row = mid / n       // 行号
 * col = mid % n       // 列号
 * matrix[mid/n][mid%n] 即一维下标 mid 对应的元素。
 *
 * 【二分过程】
 * 1. 左闭右闭区间 [left, right]，初始 right = m*n-1。
 * 2. 每轮计算 mid，获取 matrix[mid/n][mid%n]。
 * 3. 若等于 target，返回 true。
 * 4. 若小于 target，left = mid+1。
 * 5. 若大于 target，right = mid-1。
 * 6. 搜索区间为空仍未找到，返回 false。
 *
 * 【易错点】
 * 左闭右闭区间必须使用 while(left <= right)。
 * 若使用 while(left < right)，会遗漏最后一个候选元素。
 *
 *
 * 【复杂度】
 * 时间复杂度：O(log(m*n))
 * 空间复杂度：O(1)
 *
 * 二维矩阵逻辑展平，通过 mid/n 和 mid%n 映射下标，
 * 再使用普通二分查找。
 */

#include <vector>

using namespace std;

class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int temp = matrix[mid / n][mid % n];

            if (temp == target) {
                return true;
            }

            else if (temp < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }

        }

        return false;
    }
};
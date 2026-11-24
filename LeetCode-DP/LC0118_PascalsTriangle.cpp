/*
 * LeetCode 0118 - 杨辉三角 (Pascal's Triangle)
 * 难度：Easy
 * 专题：动态规划 / 二维数组 / 递推
 *
 * 题意：
 *   给定整数 numRows，生成杨辉三角的前 numRows 行。
 *   每行首尾元素都是 1，其余元素等于上一行左上方与正上方元素之和。
 *
 * 思路：
 *   1. 用 triangle[i][j] 表示第 i 行、第 j 列的元素（下标从 0 开始）。
 *   2. 第 i 行共有 i + 1 个元素，先使用 resize(i + 1, 1)
 *      将整行初始化为 1，首尾元素便无需单独处理。
 *   3. 只遍历内部位置 1 <= j < i，使用上一行递推：
 *          triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
 *   4. 最后返回整个二维数组。
 *
 * 易错点：
 *   - 第 i 行的元素数量是 i + 1，不是 i。
 *   - 内层循环必须是 j < i，避免覆盖该行最后一个 1。
 *   - 只有内部元素需要从上一行递推；i = 0 时没有内部元素。
 *   - 题目要求返回完整三角形，不能只返回最后一行。
 *
 * 时间复杂度：O(numRows^2)，需要生成约 numRows^2 / 2 个元素。
 * 空间复杂度：O(numRows^2)，用于保存题目要求返回的结果。
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; i++) {
            triangle[i].resize(i + 1, 1);

            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1]
                    + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};

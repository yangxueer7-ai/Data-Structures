
/*
 * LeetCode 0036 - 有效的数独 (Valid Sudoku)
 *
 * 算法：二维布尔数组 + 状态标记
 * 难度：Medium
 *
 * 【解题思路】
 * 给定一个 9×9 的数独棋盘，判断当前棋盘是否有效。
 * 只需检查已填入的数字，无需判断数独是否有解。
 *
 * 数独必须满足三个条件：
 * 1. 每一行的数字 1~9 不能重复。
 * 2. 每一列的数字 1~9 不能重复。
 * 3. 每个 3×3 九宫格内的数字 1~9 不能重复。
 *
 * 【状态数组】
 * bool rows[9][9]  ：记录每一行出现过的数字。
 * bool cols[9][9]  ：记录每一列出现过的数字。
 * bool boxes[9][9] ：记录每个九宫格出现过的数字。
 *
 * 第二维表示数字，使用 digit = board[i][j] - '1'
 * 将字符 '1'~'9' 映射到下标 0~8。
 *
 * 【九宫格编号】
 * 使用：
 * boxIndex = (i / 3) * 3 + j / 3;
 *
 * 将九个 3×3 九宫格映射到下标 0~8。
 *
 * 【算法流程】
 * 1. 遍历整个 9×9 棋盘。
 * 2. 遇到 '.' 直接 continue，跳过空格。
 * 3. 计算当前数字下标 digit 和九宫格编号 boxIndex。
 * 4. 检查对应行、列、九宫格是否已经出现该数字。
 * 5. 若任意一个状态为 true，则存在重复，返回 false。
 * 6. 否则将三个对应状态标记为 true。
 * 7. 遍历结束后无冲突，返回 true。
 *
 * 【复杂度分析】
 * 时间复杂度：O(1)
 *   棋盘固定为 9×9，最多检查 81 个位置。
 *   对于一般 R×C 棋盘，遍历时间为 O(R*C)。
 *
 * 空间复杂度：O(1)
 *   三个固定大小的 9×9 布尔数组，
 *   不随输入规模增长。
 *
 * 【易错点】
 * 1. '.' 表示空格，必须提前跳过。
 * 2. 字符 '1'~'9' 要转换为下标 0~8。
 * 3. 九宫格编号为 (i/3)*3+j/3，而不是简单的 i/3+j/3。
 * 4. 必须先检查重复，再将对应状态标记为 true。
 * 5. false 表示未出现，true 表示已经出现。
 * 6. 三个约束只要有一个发生冲突，就返回 false。
 */


#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                // 将字符转换为下标0~8数字
                int digit = board[i][j] - '1';
                int boxIndex = (i / 3) * 3 + j / 3;

                // 如果有一个出现过，返回false
                if (rows[i][digit] || cols[j][digit] || boxes[boxIndex][digit]) {
                    return false;
                }
                else {
                    rows[i][digit] = true;
                    cols[j][digit] = true;
                    boxes[boxIndex][digit] = true;
                }
            }
        }

        return true;
    }
};
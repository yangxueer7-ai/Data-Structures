/*
 * LeetCode 111. Minimum Depth of Binary Tree
 *
 * Core:
 * Bottom-Up DFS.
 * 左右子树分别返回最小深度，再计算当前节点的最小深度。
 *
 * 如果左右子树都存在：
 * minDepth = min(leftDepth, rightDepth) + 1
 *
 * Complexity:
 * Time O(n)
 * Space O(h)
 *
 * Key Point:
 * 最小深度必须到达“叶子节点”。
 *
 * 易错点：
 * 当某一侧子树为空时，不能直接使用
 * min(leftDepth, rightDepth) + 1，
 * ★ 因为空子树并不是一条到叶子节点的有效路径。根节点不是叶子节点
 *
 * - leftDepth == 0  → 只能走右子树
 * - rightDepth == 0 → 只能走左子树
 */

#include "TreeNode.h"
#include <algorithm>

using namespace std;

class Solution111 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (leftDepth == 0) {
            return rightDepth + 1;
        }

        if (rightDepth == 0) {
            return leftDepth + 1;
        }

        return min(leftDepth, rightDepth) + 1;
    }
}; 
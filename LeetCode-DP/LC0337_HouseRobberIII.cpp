/*
 * LeetCode 337. 打家劫舍 III (House Robber III)
 * 题型：树形动态规划 + 后序 DFS
 *
 * 【题意】
 * 房屋构成一棵二叉树，不能同时偷直接相连的父、子节点。
 * 求整棵树可获得的最大金额。
 *
 * 【状态定义】
 * dfs(root) 返回 pair<int, int> = {skip, take}：
 *   skip：不偷当前节点 root 时，该子树的最大收益；
 *   take：偷当前节点 root 时，该子树的最大收益。
 * 这里不用显式开 dp 数组：每个节点的两个 DP 状态通过递归返回值
 * 向父节点传递，且每个节点恰好计算一次。
 *
 * 【状态转移】
 * 设 left = dfs(root->left)，right = dfs(root->right)。
 * 1) 不偷当前节点：左右孩子各自可选偷或不偷，独立取最优。
 *    skip = max(left.first, left.second)
 *         + max(right.first, right.second);
 * 2) 偷当前节点：左右孩子必须不偷，但其更深后代仍可被选择。
 *    take = root->val + left.first + right.first;
 * 答案为 max(dfs(root).first, dfs(root).second)。
 *
 * 【初始化与易错点】
 * - 空节点返回 {0, 0}，代表两种状态的收益都是 0。
 * - 必须先计算左右子树，再计算当前节点：后序遍历（左、右、根）。
 * - 不偷父节点时，并非必须偷两个孩子；每个孩子可以自由取最优状态。
 * - 不可只取左右子树中较大的一个：左右子树的收益可以相加。
 *
 * 【复杂度】
 * 时间：O(n)，n 为二叉树节点数，每个节点访问一次。
 * 额外空间：O(h)，h 为树高，来自递归栈；最坏 O(n)。
 *
 * 2026-11-20：LeetCode 平台已确认 AC。
 */


#include "../LeetCode-Tree\TreeNode.h"
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return { 0, 0 };
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int skip = max(left.first, left.second)
            + max(right.first, right.second);
        int take = root->val + left.first + right.first;

        return { skip, take };
    }

    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        auto result = dfs(root);
        return max(result.first, result.second);
    }
};

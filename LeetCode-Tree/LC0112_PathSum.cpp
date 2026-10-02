/*
 * LeetCode 112. Path Sum
 *
 * Core:
 * Top-Down DFS.
 * 将剩余的 targetSum 从父节点传递给子节点：
 * nextTarget = targetSum - root->val
 *
 * 到达叶子节点时，判断：
 * targetSum == root->val
 *
 * 左右子树只要有一条满足条件即可，因此使用 ||。
 *
 * Complexity:
 * Time O(n)
 * Space O(h)
 *
 * Key Point:
 * DFS 向下传递“剩余目标值”，
 * 每经过一个节点就减去当前节点的值。
 *
 * 易错点：
 * 必须在叶子节点判断路径和。
 * 即使中途 targetSum == root->val，
 * 只要当前节点不是叶子，就不能直接返回 true。
 */

#include "TreeNode.h"


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //只有叶子节点存在才能返回true 
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        return(hasPathSum(root->left, targetSum - root->val) 
            || hasPathSum(root->right, targetSum - root->val));
    }

};
/*
 * LeetCode 226. Invert Binary Tree
 *
 * Core:
 * DFS 递归翻转左右子树，再交换左右孩子。
 *
 * invertTree() 返回已经翻转完成的子树根节点。
 * 当前节点只需要重新连接：
 * root->left = right
 * root->right = left
 *
 * Complexity:
 * Time O(n)
 * Space O(h)
 *
 * Key Point:
 * 相信递归能够处理好子树，
 * 当前层只负责重新连接左右孩子。
 */

#include "TreeNode.h"

class Solution226 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};
/*
 * LeetCode 235. Lowest Common Ancestor of a BST
 *
 * Core:
 * 利用 BST 的有序性质寻找最近公共祖先。
 *
 * - p、q 都小于 root → 去左子树
 * - p、q 都大于 root → 去右子树
 * - 否则 → 在当前节点分叉，root 即为 LCA
 *
 * Complexity:
 * Time O(h)
 * Space O(h)
 *
 * Key Point:
 * 同左往左，同右往右；
 * 一旦分叉，当前节点就是最近公共祖先。
 */
#include "TreeNode.h"

class Solution235 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
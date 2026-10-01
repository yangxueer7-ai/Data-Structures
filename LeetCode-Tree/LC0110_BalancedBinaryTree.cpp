/*
 * LeetCode 110. Balanced Binary Tree
 *
 * Core:
 * Bottom-Up DFS.
 * getHeight() 从子节点向父节点返回信息：
 * - >= 0：当前子树平衡，返回子树高度
 * - -1：当前子树不平衡
 *
 * 如果左右任一子树已经返回 -1，直接向上传递 -1；
 * 如果左右高度差 > 1，当前节点也返回 -1。
 *
 * Complexity:
 * Time O(n)
 * Space O(h)
 *
 * Key Point:
 * 使用 -1 作为哨兵值，让一个返回值同时表示
 * “子树高度”和“是否平衡”两种信息。
 */


#include "TreeNode.h"

#include <algorithm>
#include <cmath>

using namespace std;

class Solution110 {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(root->left);

        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = getHeight(root->right);

        if (rightHeight == -1) {
            return -1;
        }

        // 若左右子树高度差绝对值大于1，则也是不平衡的
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    
    }
};
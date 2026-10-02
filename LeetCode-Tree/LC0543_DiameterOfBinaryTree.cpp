/*
 * LeetCode 543. Diameter of Binary Tree
 *
 * Core:
 * Bottom-Up DFS.
 * height() 返回当前子树的高度，供父节点继续计算；
 * ans 记录遍历过程中出现的最大直径。
 *
 * 对每个节点：
 * - leftHeight + rightHeight：经过当前节点的最长路径（直径候选）
 * - max(leftHeight, rightHeight) + 1：当前子树高度，返回给父节点
 *
 * Complexity:
 * Time O(n)
 * Space O(h)
 *
 * Key Point:
 * 递归返回值 != 最终答案。
 * height() 负责向上返回“局部信息（高度）”，
 * ans 负责维护“全局答案（最大直径）”。
 *
 * 易错点：
 * 直径计算的是边数，因此是 leftHeight + rightHeight，
 * 不需要再 +1。
 */


#include "TreeNode.h"
#include <algorithm>

using namespace std;

class Solution543 {
public:
    int ans = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }

private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // 当前节点作为路径最高点时的直径
        ans = max(ans, leftHeight + rightHeight);

        // 返回给父节点的是当前子树高度 
        return max(leftHeight, rightHeight) + 1;
    }
};
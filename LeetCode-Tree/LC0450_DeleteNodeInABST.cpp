/*
 * LeetCode 450. Delete Node in a BST
 *
 * Core:
 * 利用 BST 性质递归寻找待删除节点。
 *
 * 找到节点后分情况处理：
 * 1. 没有左孩子 → 返回右孩子
 * 2. 没有右孩子 → 返回左孩子
 * 3. 左右孩子都有：(中序前驱也可以，左子树的最大值，即最右下节点）
 *    找右子树最小值（中序后继）替换当前节点，
 *    再递归删除右子树中原来的后继节点。
 *
 * Complexity:
 * Time O(h)
 * Space O(h)
 *
 * Key Point:
 * deleteNode() 返回“删除完成后的子树根节点”，
 * 因此需要：
 * root->left/right = deleteNode(...)
 *
 * BST 双孩子删除：
 * - 左子树最大值：中序前驱
 * - 右子树最小值：中序后继
 * 两种方法均可。
 *
 * 易错点：
 * 找右子树最小节点时：
 * while (minNode->left != nullptr)
 * 不能一直走到 minNode == nullptr 否则会导致空指针访问
 */

#include "TreeNode.h"

class Solution450 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        // 利用递归寻找待删除节点，左<根<右的性质
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // 情况 1：没有左孩子
            if (root->left == nullptr) {
                return root->right;
            }

            // 情况 2：没有右孩子
            if (root->right == nullptr) {
                return root->left;
            }

            // 情况 3：左右孩子都有
            // 找右子树最小节点（中序后继）
            TreeNode* minNode = root->right;

            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }

            // 用中序后继的值替换当前节点
            root->val = minNode->val;

            // 再从整个右子树中删除原来的后继节点
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }
};
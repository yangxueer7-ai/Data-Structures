/*
 * LeetCode 104. Maximum Depth of Binary Tree
 *
 * Method 1: BFS
 * - 使用层序遍历，每处理完一层 depth++。
 * - size 保存当前层节点数的“快照”。
 * - for 循环只处理当前层的 size 个节点，
 *   遍历过程中加入队列的新节点属于下一层，不会在本轮处理。
 *
 * Method 2: DFS
 * - Bottom-Up DFS。
 * - 左右子树先返回各自深度，
 *   当前节点深度 = max(leftDepth, rightDepth) + 1。
 *
 * Complexity:
 * - BFS: Time O(n), Space O(n)
 * - DFS: Time O(n), Space O(h)
 *
 * Key Point:
 * - BFS 中 queue + while 实现广度优先；
 *   size + for 才真正实现“按层遍历”。
 */

#include "TreeNode.h"
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Method 1: BFS
    int maxDepthBFS(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {

            // 保存当前层节点数
            int size = q.size();

            // 本轮只处理当前层
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                // 新加入队列的节点属于下一层，下次循环处理
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }

                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }

            // 当前层处理完毕，深度++
            depth++;
        }

        return depth;
    }


    // Method 2: DFS - Bottom-Up
    int maxDepthDFS(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepthDFS(root->left);
        int rightDepth = maxDepthDFS(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};
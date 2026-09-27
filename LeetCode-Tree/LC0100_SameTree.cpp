/*
 * ============================================================
 * LeetCode 100 - Same Tree
 * 判断两棵二叉树是否相同
 * ============================================================
 *
 * 【题目要求】
 * 给定两棵二叉树 p 和 q，判断它们是否完全相同。
 *
 * “完全相同”需要同时满足：
 * 1. 两棵树的结构完全一致；
 * 2. 对应位置节点的值完全相同。
 *
 * 例如：
 *
 *        p                 q
 *        1                 1
 *       / \               / \
 *      2   3             2   3
 *
 * → true
 *
 * 而：
 *
 *        p                 q
 *        1                 1
 *       /                   \
 *      2                     2
 *
 * 虽然节点值相同，但结构不同，因此 → false
 *
 *
 * ============================================================
 * Method 1：BFS（双队列同步遍历）
 * ============================================================
 *
 * 【核心思想】
 * 使用两个队列 q1、q2，同时保存两棵树中“对应位置”的节点。
 *
 * 每次分别从两个队列中取出 node1 和 node2，然后进行比较。
 *
 * 一共有三种情况：
 *
 * ① node1 == nullptr && node2 == nullptr
 *    → 两棵树当前位置都为空，结构一致，继续比较。
 *
 * ② node1 == nullptr || node2 == nullptr
 *    → 一个为空、一个不为空，说明结构不同，return false。
 *
 * ③ node1 和 node2 都不为空
 *    → 比较 node1->val 和 node2->val。
 *      如果不同，return false。
 *
 * 如果当前节点相同，则继续按照：
 *
 *      left  <-> left
 *      right <-> right
 *
 * 将对应孩子压入两个队列。
 * ============================================================
 * Method 2：DFS（递归）
 * ============================================================
 *
 * 【递归函数定义】
 *
 * isSameTreeDFS(p, q)
 *
 * 表示：
 * “判断以 p 和 q 为根节点的两棵子树是否完全相同。”
 *
 * 【递归出口】
 *
 * ① p == nullptr && q == nullptr
 *
 *      两边都为空
 *      → 相同
 *      → return true
 *
 * ② p == nullptr || q == nullptr
 *
 *      只有一边为空
 *      → 结构不同
 *      → return false
 *
 * ③ p->val != q->val
 *
 *      当前节点值不同
 *      → return false
 *
 *
 * 【递归关系】
 * 前面的异常情况全部排除以后：
 * return isSameTreeDFS(p->left, q->left)
 *     && isSameTreeDFS(p->right, q->right);
 *
 *
 * ============================================================
 * BFS vs DFS
 * ============================================================
 *
 * BFS：
 * - 使用两个 queue
 * - 两棵树同步进行层序遍历
 * - 显式保存待比较节点
 *
 * DFS：
 * - 使用递归
 * - 当前节点比较完成后，把问题交给左右子树
 * - 代码更加简洁，更能体现树的递归定义
 *
 *
 * ============================================================
 * 复杂度分析
 * ============================================================
 *
 * 时间复杂度：
 * O(n)
 * 最坏情况下需要比较所有对应节点。
 *
 * BFS 空间复杂度：
 * O(n)
 * 最坏情况下队列中可能同时保存大量节点。
 *
 * DFS 空间复杂度：
 * O(h)
 * h 为二叉树高度，空间主要来自递归调用栈。
 *
 * - 平衡二叉树：O(log n)
 * - 极端退化成链表：O(n)
 *
 *
 */




#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ====================
// Method 1: BFS
// ====================

bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;

    q1.push(p);
    q2.push(q);

    while (!q1.empty() && !q2.empty()) {
        TreeNode* node1 = q1.front();
        q1.pop();

        TreeNode* node2 = q2.front();
        q2.pop();

        if (node1 == nullptr && node2 == nullptr) {
            continue;
        }

        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        if (node1->val != node2->val) {
            return false;
        }

        q1.push(node1->left);
        q2.push(node2->left);

        q1.push(node1->right);
        q2.push(node2->right);
    }

    return q1.empty() && q2.empty();
}


// ====================
// Method 2: DFS
// ====================

bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }

    if (p == nullptr || q == nullptr) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSameTreeDFS(p->left, q->left)
        && isSameTreeDFS(p->right, q->right);
}


int main() {
    /*
            Tree 1              Tree 2

               1                   1
              / \                 / \
             2   3               2   3
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << boolalpha;

    cout << "BFS: " << isSameTreeBFS(p, q) << endl;
    cout << "DFS: " << isSameTreeDFS(p, q) << endl;

    return 0;
}
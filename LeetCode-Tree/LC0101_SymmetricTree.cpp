/*
 * ============================================================
 * LeetCode 101 - 对称二叉树
 * Symmetric Tree
 * ============================================================
 *
 * 【题目要求】
 * 给定二叉树根节点 root，判断该二叉树是否轴对称。
 *
 * 【核心思想】
 * 对称二叉树比较的不是“相同位置”，而是“镜像位置”：
 *
 *      左子树的左  <-> 右子树的右
 *      左子树的右  <-> 右子树的左
 *
 * 即：
 *      left  <-> right
 *      right <-> left
 *
 *
 * 【方法一：BFS】
 * 使用 queue 保存需要进行镜像比较的节点。
 *
 * 每次从队列中连续取出两个节点 r、s：
 *
 * 1. r、s 都为空：
 *      - 当前镜像位置一致，继续比较
 *
 * 2. 只有一个为空：
 *      - 结构不对称，返回 false
 *
 * 3. 两个都不为空：
 *      - 比较节点值
 *      - 值不同则返回 false
 *
 * 继续按照镜像关系成对入队：
 *
 *      r->left  <-> s->right
 *      r->right <-> s->left
 *
 *
 * 【方法二：DFS】
 * 定义递归函数：
 *
 *      isMirror(p, q)
 *
 * 表示：判断以 p、q 为根节点的两棵子树是否互为镜像。
 *
 * 递归出口：
 *
 * 1. p、q 都为空
 *      -> 两边结构一致，return true
 *
 * 2. 只有一个为空
 *      -> 结构不对称，return false
 *
 * 3. p、q 节点值不同
 *      -> return false
 *
 * 当前节点满足条件后，继续递归比较：
 *
 *      p->left  <-> q->right
 *      p->right <-> q->left
 *
 * 因此：
 *
 *      isMirror(p->left, q->right)
 *              &&
 *      isMirror(p->right, q->left)
 *
 *
 * 【BFS vs DFS】
 * BFS：用队列显式保存“下一对需要比较的节点”
 * DFS：用递归调用栈完成镜像子树的比较
 *
 * 两种方法本质完全相同：都是在不断比较“镜像位置”的两个节点。
 *
 *
 * 【复杂度】
 * 时间复杂度：O(n)
 *
 * BFS 空间复杂度：O(n)
 * DFS 空间复杂度：O(h)，最坏 O(n)
 *
 * 【测试树】
 *
 *          1
 *        /   \
 *       2     2
 *      / \   / \
 *     3   4 4   3
 *
 * 【期望输出】
 * true
 * ============================================================
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

bool isSymmetricBFS(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    queue<TreeNode*> q;

    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        TreeNode* p = q.front();
        q.pop();

        TreeNode* qNode = q.front();
        q.pop();

        if (p == nullptr && qNode == nullptr) {
            continue;
        }

        if (p == nullptr || qNode == nullptr) {
            return false;
        }

        if (p->val != qNode->val) {
            return false;
        }

        // 外侧 ↔ 外侧
        q.push(p->left);
        q.push(qNode->right);

        // 内侧 ↔ 内侧
        q.push(p->right);
        q.push(qNode->left);
    }

    return true;
}


// ====================
// Method 2: DFS
// ====================

bool isMirror(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }

    if (p == nullptr || q == nullptr) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isMirror(p->left, q->right)
        && isMirror(p->right, q->left);
}

bool isSymmetricDFS(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    return isMirror(root->left, root->right);
}

int main() {
    /*
              1
            /   \
           2     2
          / \   / \
         3   4 4   3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << boolalpha;

    cout << "BFS: " << isSymmetricBFS(root) << endl;
    cout << "DFS: " << isSymmetricDFS(root) << endl;

    return 0;
}
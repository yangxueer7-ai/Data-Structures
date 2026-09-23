/*
 * ============================================================
 * LeetCode 145 - 二叉树的后序遍历
 * Binary Tree Postorder Traversal
 * ============================================================
 *
 * 【题目要求】
 * 给定二叉树根节点 root，返回其后序遍历结果。
 *
 * 【遍历顺序】
 * 左子树 -> 右子树 -> 根节点
 *
 * 【本题实现】
 * 使用 stack<TreeNode*> 完成迭代后序遍历。
 *
 * 后序遍历直接用栈实现比较麻烦，因此利用：
 *
 *      左 -> 右 -> 根
 *
 * 反转后等价于：
 *
 *      根 -> 右 -> 左
 *
 * 所以先利用栈得到：
 *
 *      根 -> 右 -> 左
 *
 * 最后调用 reverse()，
 * 即可得到真正的后序遍历：
 *
 *      左 -> 右 -> 根
 *
 * ------------------------------------------------------------
 *
 *
 * stack 是 LIFO（后进先出）。
 *
 * 如果：
 *
 *      push(left)
 *      push(right)
 *
 * 那么 right 后入栈，会先出栈。
 *
 * 因此实际访问顺序为：
 *
 *      根 -> 右 -> 左
 *
 * 最后 reverse()：
 *
 *      左 -> 右 -> 根
 *
 * ------------------------------------------------------------
 *
 * 【核心步骤】
 *
 * 1. 根节点入栈。
 *
 * 2. 当栈不为空：
 *      - 取出栈顶节点 cur
 *      - 将 cur->val 加入 ans
 *      - 左孩子存在则入栈
 *      - 右孩子存在则入栈
 *
 * 3. 此时得到：
 *
 *      根 -> 右 -> 左
 *
 * 4. reverse(ans.begin(), ans.end())
 *
 *    得到：
 *
 *      左 -> 右 -> 根
 *
 * ------------------------------------------------------------
 *
 * 【易错点】
 *
 * 1. 后序遍历顺序是：
 *
 *      左 -> 右 -> 根
 *
 * 2. 为了构造“根 -> 右 -> 左”，
 *    入栈时必须：
 *
 *      先 push 左孩子
 *      再 push 右孩子
 *
 *    因为 stack 后进先出。
 *
 * 3. stack 的 pop() 不会返回元素：
 *
 *      TreeNode* cur = stk.top();
 *      stk.pop();
 *
 * 4. vector 添加元素使用：
 *
 *      ans.push_back(...)
 *
 *    stack 添加元素使用：
 *
 *      stk.push(...)
 *
 * 5. reverse() 需要：
 *
 *      #include <algorithm>
 *
 * ------------------------------------------------------------
 *
 * 【复杂度】
 *
 * 时间复杂度：O(n)
 *      每个节点访问一次，最后 reverse() 也是 O(n)。
 *
 * 空间复杂度：O(n)
 *      stack 和 ans 最坏都需要保存 O(n) 个节点/元素。
 *
 * ------------------------------------------------------------
 *
 * 【测试树】
 *
 *          1
 *         / \
 *        2   3
 *       / \  /
 *      4  5 6
 *
 * 【期望输出】
 *
 *      4 5 2 6 3 1
 *
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	stack<TreeNode*> stk;

	if (root == nullptr)
		return ans;

	stk.push(root);
	while (!stk.empty()) {
		TreeNode* cur = stk.top();
		stk.pop();
		ans.push_back(cur->val);

		if (cur->left != nullptr) {
			stk.push(cur->left);
		}

		if (cur->right != nullptr) {
			stk.push(cur->right);
		}
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right= new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);

	vector<int> result = postorderTraversal(root);

	cout << "Postorder Traversal: ";

	for (int x : result) {
		cout << x << " ";
	}

	cout << endl;
	return 0;
}



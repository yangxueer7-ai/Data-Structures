# 🌷 Data Structures

> C / C++ · 数据结构 · 408 · Algorithm · LeetCode

Hi，这里是我的 **数据结构与算法学习仓库** 👋

最开始只是用来存放本科数据结构课程的实验和作业，后来开始准备 408，也重新把以前写过的代码一点点整理起来。

现在这里主要记录：

- 数据结构基础实现
- 408 常见题型
- C / C++ 练习
- LeetCode 专题刷题
- 算法与解题思路整理

目前主要使用 **C / C++**。

希望这个仓库可以陪我从：

> **“好像学过” → “我真的会写” ✨**

---

g## 📌 Current Progress

| Topic | Status | Notes |
|---|---|---|
| Linear List | ✅ 基础完成 | 顺序表 / 链表 |
| Stack & Queue | ✅ 基础完成 | 栈 / 队列 |
| Tree | 🚧 持续整理 | DFS / BFS / BST |
| Array | 🚧 正在刷 | 双指针 / 多指针 |
| Dynamic Programming | 🚧 正在刷 | 一维 / 二维 / 滚动数组 |
| Greedy | 🚧 正在刷 | 股票 / 跳跃 |
| Graph | ⏳ 待开始 | |
| Backtracking | ⏳ 待开始 | |
| Sorting | ⏳ 待系统整理 | |

---

## 📁 Repository Structure

```text
Data-Structures/
│
├── 01-Linear-List/          # 线性表
├── 02-Stack-Queue/          # 栈与队列
├── 03-Tree/                 # 树与二叉树基础实现
├── Coursework/              # 本科课程实验 & 作业
├── LeetCode-Array/          # 数组 / 双指针 / 多指针
├── LeetCode-DP/             # 动态规划
├── LeetCode-Greedy/         # 贪心
├── LeetCode-Tree/           # 二叉树 / BST 专题
├── main.cpp
└── README.md
```

暂时不会提前创建很多空目录。

学到哪里，就整理到哪里 🌱

---

# 📚 Learning Roadmap

## 01 · Linear List 线性表

- ✅ 顺序表基础实现
- ✅ 链表基础实现
- ✅ 常见插入 / 删除 / 查找
- 🚧 408 常见操作整理
- 🚧 相关算法题

## 02 · Stack & Queue 栈与队列

- ✅ Stack 基础实现
- ✅ Queue 基础实现
- 🚧 循环队列
- 🚧 链栈 / 链队列
- 🚧 408 常见题型
- 🚧 相关算法题

## 03 · Tree 树与二叉树

目前主要在整理：

- ✅ 前序 / 中序 / 后序遍历
- ✅ 层序遍历
- ✅ 最大 / 最小深度
- ✅ 平衡二叉树
- ✅ 路径问题
- ✅ 二叉树比较
- ✅ 最近公共祖先
- ✅ BST 搜索 / 插入 / 删除
- ✅ BST 最近公共祖先
- 🚧 二叉树构造
- ⏳ AVL
- ⏳ Huffman Tree

树题目前最常用的思考：

```text
看到树题
   ↓
先判断 DFS / BFS
   ↓
递归函数返回什么？
   ↓
当前节点要做什么？
   ↓
左右子树怎么处理？
```

---

# 🧩 LeetCode Topics

## 🟦 Array & Two Pointers

目前重点：

- 快慢指针
- 左右指针
- 三指针
- 原地修改
- 有序数组
- 区间处理

已经整理的代表题：

```text
LC26   Remove Duplicates from Sorted Array
LC27   Remove Element
LC75   Sort Colors
LC88   Merge Sorted Array
LC125  Valid Palindrome
LC167  Two Sum II
LC283  Move Zeroes
LC344  Reverse String
LC977  Squares of a Sorted Array
```

目前总结出的几个常用套路：

```text
fast：负责扫描
slow：负责写入

left / right：
从两端向中间收缩

多指针：
不同指针维护不同区间
```

### ⭐ 当前最重要的理解

```text
fast 找我要的
slow 把我要的写到前面
```

以及：

```text
left / right 并不是 C++ 真正的指针
本质上通常只是数组下标
```

---

## 🟨 Dynamic Programming

目前已经覆盖：

- ✅ 一维基础 DP
- ✅ “选 / 不选”型 DP
- ✅ 二维网格 DP
- ✅ 滚动数组
- ✅ 空间压缩
- ✅ 环形 DP
- 🚧 更多经典模型
- ⏳ 0/1 背包

代表题：

```text
LC53   Maximum Subarray
LC62   Unique Paths
LC63   Unique Paths II
LC64   Minimum Path Sum
LC70   Climbing Stairs
LC120  Triangle
LC198  House Robber
LC213  House Robber II
LC746  Min Cost Climbing Stairs
```

### 🧠 DP 思考顺序

```text
1. dp[i] / dp[i][j] 表示什么？
2. 当前状态从哪里来？
3. 状态转移方程是什么？
4. 初始状态是什么？
5. 遍历顺序是什么？
6. 最后返回哪个状态？
```

> **状态定义决定初始化、转移方程、遍历顺序和最终返回值。**

二维 DP 压缩成一维时：

```text
左边是新的
上面是旧的
```

---

## 🟩 Greedy 贪心

目前已经整理：

```text
LC55   Jump Game
LC121  Best Time to Buy and Sell Stock
LC122  Best Time to Buy and Sell Stock II
```

目前对贪心的理解：

```text
不一定枚举完整方案
↓
维护当前最优 / 历史最优
↓
通过局部最优不断推进
```

典型思路：

```text
LC121：维护历史最低价 + 假设今天卖出
LC122：所有正涨幅全部拿走
LC55：不关心具体怎么跳，只维护当前最远能到哪里
```

---

# 💻 C / C++

这个仓库会同时使用 **C 和 C++**。

学习数据结构的时候，我还是希望自己能够真正理解：

- 指针
- 内存
- 结构体
- 顺序存储
- 链式存储
- 数组下标
- 引用
- STL 容器

同时也会继续熟悉：

```text
vector
stack
queue
map
unordered_map
set
algorithm
string
...
```

目标不是重复造所有轮子，而是至少知道：

> **轮子是怎么造出来的，以及什么时候应该用什么轮子。**

---

# 🎯 For 408

现阶段主要目标：

> **408 数据结构 + C/C++ + 算法基础**

希望复习每一部分时，都能做到：

- 📖 理解基本概念和原理
- ✍️ 自己写出核心数据结构
- ⏱️ 会分析时间 / 空间复杂度
- 💻 能用 C / C++ 独立实现
- 🧠 知道对应的常见算法和题型
- 🛠️ 能自己 Debug
- ✅ 最后真正用它解决问题

理想状态：

```text
看到题目
   ↓
识别题型
   ↓
想到数据结构 / 算法
   ↓
设计状态 / 指针 / 数据结构
   ↓
C / C++ 实现
   ↓
Debug
   ↓
AC ✓
```

---

# 🎓 Coursework

`Coursework/` 里保存的是之前本科数据结构课程的实验和作业。

之后复习到对应内容时，可以：

```text
旧实现
   ↓
重新理解
   ↓
重新实现
   ↓
比较两版代码
```

这样也能看到自己一点点进步的过程 🌱

---

# 📈 Recent Focus

最近主要在练：

```text
Array
   ↓
Two Pointers
   ↓
Multiple Pointers
   ↓
DP
   ↓
Greedy
```

当前阶段希望先把这些基础套路刷熟：

- 数组下标与边界
- 快慢指针
- 左右指针
- 三指针
- DP 状态定义
- 滚动数组
- 贪心中的“当前最优 / 历史最优”

比起追求刷很多题，目前更希望：

> **同一类题真正形成自己的模板和直觉。**

---

# 🚧 Next

接下来准备继续：

```text
Array / Two Pointers
Dynamic Programming
Greedy
Graph
Backtracking
Sorting
Hash
Heap
```

之后也会继续增加新的 LeetCode 专题目录：

```text
LeetCode-Graph
LeetCode-Backtracking
LeetCode-Hash
LeetCode-Heap
...
```

不过还是不会提前建很多空目录。

**学到哪里，写到哪里。**

---

# ✅ Learning Rule

这个仓库不追求短时间塞进很多题。

更希望每一道保留下来的题，都经历过：

```text
自己想
   ↓
自己写
   ↓
报错
   ↓
Debug
   ↓
理解错误原因
   ↓
优化
   ↓
整理注释
   ↓
Git Commit
```

真正做到：

> **写过了、错过了、改过了、AC 了、弄懂了。**

---

# ✨ Keep Learning

这个仓库会随着学习进度慢慢更新。

今天多理解一个指针，

明天多弄懂一个状态转移，

再多 AC 一道题。

一点一点来就好啦 🌷

### Keep learning, keep coding.

**408 · C/C++ · Data Structures · Algorithm · LeetCode**

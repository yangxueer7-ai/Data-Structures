/*
 * LeetCode 49. 字母异位词分组 (Group Anagrams)
 * 难度：Medium
 * 算法：哈希表 / 字符串排序 / STL
 *
 * 【题意】
 * 给定字符串数组 strs，将字母异位词分到同一组。
 * 字母异位词：字符种类及出现次数相同，排列顺序可以不同。
 *
 * 【核心思路】
 * 字母异位词经过排序后，一定具有相同的字符串。
 * 因此将排序后的字符串作为哈希表 key，
 * 将原始字符串存入对应的 vector<string>，完成分组。
 *
 * 【哈希表定义】
 * unordered_map<string, vector<string>> mp;
 *
 * key   ：排序后的字符串，如 "aet"。
 * value ：该组的原始字符串，如 {"eat", "tea", "ate"}。
 *
 * 【算法过程】
 * 1. 遍历 strs 中的每个字符串 s。
 * 2. 复制字符串：string key = s。
 * 3. 排序 key，生成统一的分组标识。
 * 4. mp[key].push_back(s)，将原始字符串加入对应分组。
 * 5. 遍历哈希表，使用 entry.second 收集所有分组。
 * 6. 返回 ans。
 *
 * 【STL / C++ 新语法】★
 *
 * ① unordered_map<string, vector<string>>
 *    无序关联容器，存储 key-value 键值对。
 *    string 是键类型，vector<string> 是值类型。
 *    哈希表查找、插入的平均时间复杂度为 O(1)。
 *
 * ② for (const string& s : strs)
 *    C++11 范围 for 循环，依次访问容器中的元素。
 *    const：禁止通过 s 修改原字符串。
 *    &    ：引用，避免复制整个字符串。
 *    s    ：当前遍历到的字符串。
 *
 * ③ string key = s;
 *    复制一份原始字符串。
 *    修改 key 不会影响 s。
 *    因此可以排序 key，同时保留原字符串。
 *
 * ④ sort(key.begin(), key.end());
 *    STL algorithm 中的排序函数。
 *    begin()：返回首元素迭代器。
 *    end()  ：返回尾后迭代器（不指向实际元素）。
 *    sort 对 [begin, end) 范围进行升序排序。
 *
 * ⑤ mp[key].push_back(s);
 *    mp[key]：访问 key 对应的 vector<string>。
 *    如果 key 不存在，会自动创建一个空 vector<string>。
 *    push_back(s)：将原始字符串追加到该 vector 末尾。
 *
 * ⑥ for (const auto& entry : mp)
 *    auto  ：由编译器自动推导变量类型。
 *    &     ：引用，避免复制整个键值对。
 *    const ：只读访问，不修改哈希表元素。
 *
 *    entry 的类型相当于：
 *    const pair<const string, vector<string>>&
 *
 * ⑦ entry.first / entry.second
 *    unordered_map 中的每个元素都是一个 pair（键值对）。
 *    entry.first  ：key，即排序后的字符串。
 *    entry.second ：value，即原始字符串组成的 vector。
 *
 *    本题需要返回所有字符串分组，
 *    因此 ans.push_back(entry.second)。
 *
 * 【易错点】
 * 1. key 是排序后的字符串，s 是原始字符串。
 * 2. 必须 push_back(s)，不能 push_back(key)，否则丢失原始内容。
 * 3. mp[key] 不存在时会自动创建对应的空 vector。
 * 4. entry.first 是键，entry.second 才是需要返回的分组。
 * 5. unordered_map 不保证遍历顺序，本题允许任意顺序。
 * 6. sort 使用左闭右开范围 [begin(), end())。
 *
 * 【复杂度】
 * 设 N 为字符串数量，K 为字符串平均长度。
 * 时间复杂度：平均 O(N*K*logK)，主要来自排序。
 * 空间复杂度：O(N*K)，用于哈希表和字符串分组。
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (const auto& entry : mp) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};
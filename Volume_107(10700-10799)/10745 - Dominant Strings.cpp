// clang-format off
// 題目目標：從輸入的所有字串中，找出「不被任何其他字串支配」的 dominant strings，並按照字典順序輸出。
// 定義：字串 A 支配 B，若 A 的每個字母出現次數都 ≥ B，且至少一個字母的出現次數 > B。
// 
// 解法：
// 1. 將每個字串轉為長度 26 的 freq 陣列，記錄每個字母出現次數。
// 2. 建立一棵 Trie，深度為 26，每層有 11 個分支（代表每個字母最多出現 0~10 次）。
// 3. 將所有字串的 freq 陣列插入 Trie，並記錄該 freq 對應哪些字串 id。
// 4. 對每個字串，從 Trie 中搜尋所有「它可以支配的 freq 組合」，把那些 id 標記為 dominated。
// 5. 輸出所有沒被支配的字串，並以 set 排序輸出。
// clang-format on
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  TrieNode *next[11] = {};
  vector<int> ids;
};

void insert(TrieNode *root, const vector<int> &freq, int id) {
  TrieNode *cur = root;
  for (int i = 0; i < 26; ++i) {
    int cnt = freq[i];
    if (!cur->next[cnt])
      cur->next[cnt] = new TrieNode();
    cur = cur->next[cnt];
  }
  cur->ids.push_back(id);
}

void dfs(TrieNode *node, const vector<int> &freq, vector<bool> &dominated,
         int depth = 0, bool istrict = false) {
  if (depth == 26) {
    if (istrict) {
      for (int id : node->ids)
        dominated[id] = true;
    }
    return;
  }

  for (int i = 0; i <= freq[depth]; ++i) {
    if (node->next[i]) {
      bool newstrict = istrict || (i < freq[depth]);
      dfs(node->next[i], freq, dominated, depth + 1, newstrict);
    }
  }
}

int main() {
  string s;
  TrieNode root;

  vector<string> strings;
  vector<vector<int>> freqs;
  vector<bool> dominated;

  int i = 0;
  while (cin >> s) {
    strings.push_back(s);
    vector<int> freq(26);
    for (char c : s)
      ++freq[c - 'a'];
    insert(&root, freq, i++);
    freqs.push_back(freq);
    dominated.push_back(false);
  }

  int n = i;
  for (int i = 0; i < n; ++i)
    dfs(&root, freqs[i], dominated);

  set<string> res;
  for (int i = 0; i < n; ++i)
    if (!dominated[i])
      res.insert(strings[i]);

  for (const string &s : res)
    cout << s << '\n';
  return 0;
}

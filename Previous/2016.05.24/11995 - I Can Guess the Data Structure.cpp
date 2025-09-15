#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
  int t;
  while (cin >> t) {
    stack<int> st;
    queue<int> qu;
    priority_queue<int> pq;

    bool is_st = true, is_qu = true, is_pq = true;

    for (int i = 0; i < t; ++i) {
      int op, x;
      cin >> op >> x;
      if (op == 1) {
        st.push(x);
        qu.push(x);
        pq.push(x);
      } else {
        if (is_st) {
          if (st.empty() || st.top() != x)
            is_st = false;
          else
            st.pop();
        }
        if (is_qu) {
          if (qu.empty() || qu.front() != x)
            is_qu = false;
          else
            qu.pop();
        }
        if (is_pq) {
          if (pq.empty() || pq.top() != x)
            is_pq = false;
          else
            pq.pop();
        }
      }
    }

    int cnt = is_st + is_qu + is_pq;
    if (cnt == 0)
      cout << "impossible\n";
    else if (cnt > 1)
      cout << "not sure\n";
    else if (is_st)
      cout << "stack\n";
    else if (is_qu)
      cout << "queue\n";
    else
      cout << "priority queue\n";
  }
  return 0;
}

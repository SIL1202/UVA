#include <iostream>
#include <vector>
using namespace std;

static vector<int> fib;
void Fib(int limit) {
  fib.clear();
  fib.push_back(1);
  fib.push_back(2);
  while (true) {
    long long nxt = 1LL * fib[fib.size() - 1] + fib[fib.size() - 2];
    if (nxt > limit)
      break;
    fib.push_back((int)nxt);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> xs(n);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> xs[i];
    if (xs[i] > mx)
      mx = xs[i];
  }
  Fib(mx); // init fib

  for (int t = 0; t < n; ++t) {
    int x = xs[t];
    cout << x << " = ";

    if (x == 0) {
      cout << "0 (fib)\n";
      continue;
    }

    size_t i = 0;
    while (i < fib.size() && fib[i] <= x)
      ++i;
    if (i)
      --i;

    for (;;) {
      if (x >= fib[i]) {
        x -= fib[i];
        cout << '1';
      } else
        cout << '0';
      if (i == 0)
        break;
      --i;
    }
    cout << " (fib)\n";
  }
  return 0;
}

// 1 2 3 5 8
// 0 0 0 0 0

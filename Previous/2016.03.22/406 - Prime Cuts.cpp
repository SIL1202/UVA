#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static vector<int> primes = {1, 2};

bool is_prime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

void ensure_primes_upto(int n) {
  for (int x = primes.back() + 1; x <= n; ++x)
    if (is_prime(x))
      primes.push_back(x);
}

int main() {
  int n, c;
  while (cin >> n >> c) {
    ensure_primes_upto(n);

    int m = upper_bound(primes.begin(), primes.end(), n) - primes.begin();

    int want = (m % 2 == 0) ? 2 * c : 2 * c - 1;
    int take = min(want, m);

    int start = (m - take) / 2;
    int end = start + take;

    cout << n << ' ' << c << ":";
    for (int i = start; i < end; ++i)
      cout << ' ' << primes[i];
    puts("\n");
  }
  return 0;
}

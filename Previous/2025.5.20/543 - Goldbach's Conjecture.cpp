#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX, true);
vector<int> primes;

void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < MAX; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (long long j = 1LL * i * i; j < MAX; j += i)
        is_prime[j] = false;
    }
  }
}

int main() {
  sieve();
  int n;
  while (cin >> n && n != 0) {
    bool found = false;
    for (int i = 0; primes[i] <= n / 2; ++i) {
      int a = primes[i];
      int b = n - a;
      if (is_prime[b]) {
        cout << n << " = " << a << " + " << b << '\n';
        found = true;
        break;
      }
    }
    if (!found)
      cout << "Goldbach's conjecture is wrong.";
  }
  return 0;
}

#include <iostream>
using namespace std;
#define ll long long

bool isPrime(ll v) {
  if (v == 2)
    return true;
  if (v < 2 || v % 2 == 0)
    return false;

  for (ll i = 3; i * i <= v; i += 2)
    if (v % i == 0)
      return false;
  return true;
}

ll reverse(ll v) {
  ll x = 0;
  while (v != 0) {
    x = x * 10 + v % 10;
    v /= 10;
  }
  return x;
}

int main() {
  ll n;
  while (cin >> n) {
    if (isPrime(n) && isPrime(reverse(n)) && n != reverse(n))
      cout << n << " is emirp.\n";
    else if (isPrime(n))
      cout << n << " is prime.\n";
    else
      cout << n << " is not prime.\n";
  }
  return 0;
}

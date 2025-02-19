#include <bitset>
#include <iostream>
#include <string>
using namespace std;

void solve() {
  int m;
  cin >> m;
  bitset<16> binary(m);
  int b1 = binary.count();

  int hex_value = stoi(to_string(m), nullptr, 16);
  int b2 = bitset<16>(hex_value).count();
  cout << b1 << " " << b2 << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}

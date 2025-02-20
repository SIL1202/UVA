#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    bitset<32> binary(n);
    string ans = binary.to_string();

    cout << "The parity of " << ans.substr(ans.find('1')) << " is "
         << binary.count() << " (mod 2).\n";
  }
  return 0;
}

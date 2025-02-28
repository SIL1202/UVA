#include <iostream>
#include <string>
using namespace std;
int gcd_euclid(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int GCD(string &s1, string &s2) {
  int num1 = stoi(s1, nullptr, 2);
  int num2 = stoi(s2, nullptr, 2);
  return gcd_euclid(num1, num2);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string S, L;
    cin >> S >> L;
    int gcd = GCD(S, L);
    cout << "Pair #" << i + 1
         << (gcd > 1 ? ": All you need is love!\n"
                     : ": Love is not all you need!\n");
  }
  return 0;
}
